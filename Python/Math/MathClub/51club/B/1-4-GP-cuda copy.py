import numpy as np
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
from itertools import islice
import random
from scipy.optimize import minimize
from deap import creator, base, tools, algorithms
import pycuda.autoinit
import pycuda.driver as cuda
from pycuda.compiler import SourceModule

def read_excel_data(filepath):
    # Load Excel data once and return the demands and the dataframe
    demands = {}
    try:
        demands_dataframe = pd.read_excel(filepath, sheet_name='Demands')
        for index, row in demands_dataframe.iterrows():
            origin_destination = (row['Start'], row['End'])
            demand_value = row['Demand']
            demands[origin_destination] = demand_value * 1.0
        return demands, demands_dataframe
    except Exception as e:
        print(f"Error reading the Excel file: {e}")
        return {}, pd.DataFrame()

def create_graph():
    # Creating a predefined graph structure
    G = nx.Graph()
    edges = [(1, 2), (1, 4), 
             (2, 3), (2, 5),
             (3, 6),
             (4, 5), (4, 7),
             (5, 6), (5, 8),
             (6, 9),
             (7, 8),
             (8, 9)]
    G.add_edges_from(edges)
    return G

def generate_all_paths(G, source, target, cutoff=None):
    # Generate all simple paths from source to target with optional cutoff
    return list(nx.all_simple_paths(G, source=source, target=target, cutoff=cutoff))

# 定义适应度函数的CUDA核函数
cuda_kernel = """
__global__ void evaluate_kernel(float *individual, float *demands, float *paths_dict, float *fitness_results, int total_network_demand, int num_paths, int num_demands) {
    // 获取当前线程的索引
    int tid = blockIdx.x * blockDim.x + threadIdx.x;

    // 检查线程索引是否在有效范围内
    if (tid < num_demands) {
        float successful_demand = 0;

        // 遍历每个需求
        for (int demand_idx = tid; demand_idx < num_demands; demand_idx += blockDim.x * gridDim.x) {
            float *path_weights = new float[num_paths];
            float *individual_ptr = individual + demand_idx * num_paths;
            float *demands_ptr = demands + demand_idx;
            float *paths_dict_ptr = paths_dict + demand_idx * num_paths;
            
            // 遍历每个路径
            for (int path_idx = 0; path_idx < num_paths; ++path_idx) {
                path_weights[path_idx] = individual_ptr[path_idx];
            }

            // 归一化权重
            float total_weight = 0;
            for (int path_idx = 0; path_idx < num_paths; ++path_idx) {
                total_weight += path_weights[path_idx];
            }
            for (int path_idx = 0; path_idx < num_paths; ++path_idx) {
                path_weights[path_idx] /= total_weight != 0 ? total_weight : 1;
            }

            // 计算每个路径的成功概率和需求
            for (int path_idx = 0; path_idx < num_paths; ++path_idx) {
                float path_failure_prob = 1 - powf(1 - 1 / 12, paths_dict_ptr[path_idx]);
                float successful_prob = 1 - path_failure_prob;
                float path_demand = *demands_ptr * successful_prob * path_weights[path_idx];
                successful_demand += path_demand;
            }
            delete [] path_weights; // 释放动态分配的内存
        }

        // 将结果存储到适应度结果数组中
        fitness_results[tid] = successful_demand / total_network_demand;
    }
}
"""

# 编译CUDA核函数
mod = SourceModule(cuda_kernel)

# 获取CUDA核函数
evaluate_kernel = mod.get_function("evaluate_kernel")

# 定义一个函数来计算适应度函数的CUDA加速版本
# 修改evaluate_cuda函数
def evaluate_cuda(individual, demands, paths_dict):

    max_length = max(len(path) for paths in paths_dict.values() for path in paths)
    padded_paths_dict = {key: [path + [0] * (max_length - len(path)) for path in paths] for key, paths in paths_dict.items()}
    paths_dict_np = np.array([[len(path) - 1 for path in paths] for paths in padded_paths_dict.values()], dtype=np.float32)


    # 将输入数据转换为numpy数组


    individual_np = np.array(individual, dtype=np.float32)
    demands_np = np.array(list(demands.values()), dtype=np.float32)
    paths_dict_np = np.array([[len(path) - 1 for path in paths] for paths in padded_paths_dict.values()], dtype=np.float32)
    total_network_demand = np.sum(demands_np)

    # 获取数据维度信息
    num_demands = len(demands)
    num_paths = len(paths_dict_np[0])

    # 分配CUDA内存来存储输入数据和适应度结果
    individual_gpu = cuda.mem_alloc(individual_np.nbytes)
    demands_gpu = cuda.mem_alloc(demands_np.nbytes)
    paths_dict_gpu = cuda.mem_alloc(paths_dict_np.nbytes)
    fitness_results_gpu = cuda.mem_alloc(num_demands * np.dtype(np.float32).itemsize)

    # 将输入数据复制到CUDA内存中
    cuda.memcpy_htod(individual_gpu, individual_np)
    cuda.memcpy_htod(demands_gpu, demands_np)
    cuda.memcpy_htod(paths_dict_gpu, paths_dict_np)

    # 定义CUDA块和线程的大小
    block_size = 256
    grid_size = (num_demands + block_size - 1) // block_size

    # 调用CUDA核函数计算适应度
    evaluate_kernel(individual_gpu, demands_gpu, paths_dict_gpu, fitness_results_gpu, np.int32(total_network_demand), np.int32(num_paths), np.int32(num_demands), block=(block_size, 1, 1), grid=(grid_size, 1))

    # 分配内存来存储适应度结果
    fitness_results = np.empty(num_demands, dtype=np.float32)

    # 将适应度结果从CUDA内存复制到主机内存中
    cuda.memcpy_dtoh(fitness_results, fitness_results_gpu)

    return fitness_results



def checkBounds(min, max):
    # Decorator to enforce bounds on mutation
    def decorator(func):
        def wrappper(*args, **kargs):
            offspring = func(*args, **kargs)
            for child in offspring:
                for i in range(len(child)):
                    if child[i] > max:
                        child[i] = max
                    elif child[i] < min:
                        child[i] = min
            return offspring
        return wrappper
    return decorator

# Initialization and genetic algorithm setup
def setup_genetic_algorithm(demands, paths_dict):
    n_genes = sum(len(paths) for paths in paths_dict.values())  # Calculate total number of genes required
    creator.create("FitnessMax", base.Fitness, weights=(1.0,))
    creator.create("Individual", list, fitness=creator.FitnessMax)
    toolbox = base.Toolbox()
    toolbox.register("attr_float", random.random)
    toolbox.register("individual", tools.initRepeat, creator.Individual,
                     toolbox.attr_float, n=n_genes)
    toolbox.register("population", tools.initRepeat, list, toolbox.individual)
    toolbox.register("evaluate", evaluate_cuda, demands=demands, paths_dict=paths_dict)
    toolbox.register("mate", tools.cxTwoPoint)
    toolbox.register("select", tools.selTournament, tournsize=3)
    toolbox.register("mutate", tools.mutGaussian, mu=0, sigma=0.1, indpb=0.2)
    toolbox.decorate("mutate", checkBounds(0, 1))
    return toolbox

def main():
    # Main function to run the genetic algorithm
    filepath = r'Python/Math/MathClub/51Club/B//data/TDNetwork2.xlsx'
    demands, _ = read_excel_data(filepath)
    G = create_graph()
    paths_dict = {key: generate_all_paths(G, *key) for key in demands.keys()}
    toolbox = setup_genetic_algorithm(demands, paths_dict)

    population = toolbox.population(n=300)
    NGEN = 80
    best_fitness = []

    all_generations_data = []

    for gen in range(NGEN):
        offspring = algorithms.varAnd(population, toolbox, cxpb=0.5, mutpb=0.2)
        fits = map(toolbox.evaluate, offspring)

        gen_data = []

        for fit, ind in zip(fits, offspring):
            ind.fitness.values = fit
            
            path_info = []
            individual = ind[:]
            for (source, target), paths in paths_dict.items():
                path_weights = individual[:len(paths)]
                individual = individual[len(paths):]
                normalized_weights = np.clip(path_weights, 0, 1)
                normalized_weights /= np.sum(normalized_weights) if np.sum(normalized_weights) != 0 else 1

                for path_idx, path in enumerate(paths):
                    path_demand = demands[(source, target)] * normalized_weights[path_idx]
                    path_info.append({'Source': source, 'Target': target, 'Path': path, 'Assigned Demand': path_demand})
            
            gen_data.extend(path_info)

        #存储这一代数据DataFrame添加到列表
        if gen > 75:
            all_generations_data.append(pd.DataFrame(gen_data))

        population = toolbox.select(offspring, k=len(population))
        best_individual = tools.selBest(population, k=1)[0]
        best_fitness.append(best_individual.fitness.values[0])
    # 将所有代数据合并到一个DataFrame
    all_generations_data = pd.concat(all_generations_data,ignore_index=True)
    # 保存数据到Excel
    all_generations_data.to_excel('output_path_flows.xlsx',index=False)
    # 绘图展示适应度随代数的变化
    plt.figure(figsize=(10, 5))
    plt.plot(best_fitness, label='Best Fitness')
    plt.title('Best Fitness Over Generations')
    plt.xlabel('Generation')
    plt.ylabel('Fitness')
    plt.legend()
    plt.grid(True)
    plt.show()

    print("Best Fitness:", best_individual.fitness.values[0])

if __name__ == "__main__":
    main()
