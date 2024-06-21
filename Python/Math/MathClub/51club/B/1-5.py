import numpy as np
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
from itertools import islice
import random
from deap import creator, base, tools, algorithms
from datetime import datetime
from pycuda.compiler import SourceModule
import pycuda.autoinit
import pycuda.driver as cuda
import os
os.environ['PATH'] += ';'+r"D:\Visual Studio\IDE\VC\Tools\MSVC\14.38.33130\bin\Hostx64\x64"

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

def generate_k_shortest_paths(G, source, target, k=5):
    """Generate k shortest simple paths from source to target in the graph G."""
    try:
        return list(islice(nx.shortest_simple_paths(G, source, target, weight=None), k))
    except nx.NetworkXNoPath:
        print(f"No path between {source} and {target}")
        return []
    
    
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


# 编译 CUDA 核函数
mod = SourceModule("""
__global__ void evaluate_fitness_kernel(float *individual, float *demands, float *path_lengths, float *result, int num_paths, int num_demands) {
    int individual_idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (individual_idx < num_demands) {
        int demand_idx = individual_idx * num_paths;
        float total_demand = 0.0;

        for (int path_idx = 0; path_idx < num_paths; path_idx++) {
            float path_weight = individual[demand_idx + path_idx];
            float path_length = path_lengths[demand_idx + path_idx];
            float path_failure_prob = 1 - powf(1 - 1.0/12, path_length - 1);
            float successful_prob = 1 - path_failure_prob;
            float demand = demands[individual_idx] * successful_prob * path_weight;
            total_demand += demand;
        }

        result[individual_idx] = total_demand;
    }
}
""")

evaluate_fitness_gpu = mod.get_function("evaluate_fitness_kernel")
# 定义适应度函数，将其移动到 GPU 上执行
def evaluate_fitness_with_cuda(individual, demands_values, path_lengths):
    num_paths = individual.shape[1]  # 获取路径数
    num_demands = individual.shape[0]  # 获取需求数

    # 分配 GPU 内存
    individual_gpu = cuda.mem_alloc(individual.nbytes)
    demands_values_gpu = cuda.mem_alloc(demands_values.nbytes)
    path_lengths_gpu = cuda.mem_alloc(path_lengths.nbytes)
    result_gpu = cuda.mem_alloc(num_demands * np.float32().itemsize)

    # 将数据传输到 GPU 内存
    cuda.memcpy_htod(individual_gpu, individual)
    cuda.memcpy_htod(demands_values_gpu, demands_values)
    cuda.memcpy_htod(path_lengths_gpu, path_lengths)

    # 设置 GPU 核函数参数并执行
    block_size = 256
    grid_size = (num_demands + block_size - 1) // block_size
    evaluate_fitness_gpu(individual_gpu, demands_values_gpu, path_lengths_gpu, result_gpu, np.int32(num_paths), np.int32(num_demands), block=(block_size, 1, 1), grid=(grid_size, 1))

    # 从 GPU 内存中检索结果
    result = np.empty(num_demands, dtype=np.float32)
    cuda.memcpy_dtoh(result, result_gpu)
    return result


def setup_genetic_algorithm(demands_values, path_lengths):

    n_genes = sum(path_lengths)  # 计算总基因数

    creator.create("FitnessMax", base.Fitness, weights=(1.0,))
    creator.create("Individual", list, fitness=creator.FitnessMax)
    #注册生成个体的函数
    toolbox = base.Toolbox()
    toolbox.register("attr_float", random.random)
    toolbox.register("individual", tools.initRepeat, creator.Individual,
                     toolbox.attr_float, n=n_genes)
    toolbox.register("population", tools.initRepeat, list, toolbox.individual)
    #注册适应度评估函数
    toolbox.register("evaluate", evaluate_fitness_with_cuda, 
                     demands_values=demands_values, path_lengths=path_lengths)
    #注册交叉和选择操作
    toolbox.register("mate", tools.cxTwoPoint)
    toolbox.register("select", tools.selTournament, tournsize=3)
    toolbox.register("mutate", tools.mutGaussian, mu=0, sigma=0.1, indpb=0.2)
    toolbox.decorate("mutate", checkBounds(0, 1))
    return toolbox


def main():
    filepath = r'data/TDNetwork2.xlsx'

    demands_dict, _ = read_excel_data(filepath)
    demands_keys = list(demands_dict.keys())
    demands_values = np.array(list(demands_dict.values()))

    G = create_graph()
    paths_dict = {key: generate_k_shortest_paths(G, *key) for key in demands_keys}
    path_lengths = np.array([len(path) for paths in paths_dict.values() for path in paths])

    toolbox = setup_genetic_algorithm(demands_values,path_lengths) #定义工具箱 非常重要的一步

    population = toolbox.population(n=300)
    NGEN = 55
    best_fitness = []

    with pd.ExcelWriter('GP-data-5Gen'+datetime.now().strftime("%m%d%H%M")+'.xlsx') as writer:
        for gen in range(NGEN):
            offspring = algorithms.varAnd(population, toolbox, cxpb=0.5, mutpb=0.2)
            fits = map(toolbox.evaluate, offspring)#对新生成的个体进行适应度评估 存入fits
            gen_data = []

            for fit, ind in zip(fits, offspring): #遍历每个个体
                ind.fitness.values = fit   #个体适应值存入
                path_info = []
                individual = ind[:]
                for (source, target), paths in paths_dict.items():#外 遍历起止对-内 遍历对应的路径
                    path_weights = individual[:len(paths)]#个体基因提取路径权重
                    individual = individual[len(paths):] #更新个体，去除已经处理的路径权重
                    normalized_weights = np.clip(path_weights, 0, 1)#路径权重限制在0-1之间
                    normalized_weights /= np.sum(normalized_weights) if np.sum(normalized_weights) != 0 else 1
                    #路径权重归一化 确保总和为1
                    for path_idx, path in enumerate(paths):
                        path_demand = demands_dict[(source, target)] * normalized_weights[path_idx]
                        path_info.append({'Source': source, 'Target': target, 'Path': path, 'Assigned Demand': path_demand})

                gen_data.extend(path_info)
            df = pd.DataFrame(gen_data)
            df.to_excel(writer, sheet_name=f'Generation_{gen}', index=False)

            population = toolbox.select(offspring, k=len(population))#使用选择操作选择下一代的个体(实现进化)
            best_individual = tools.selBest(population, k=1)[0]#选择当前代的最优个体
            best_fitness.append(best_individual.fitness.values[0])#将最优个体的适应度值添加到列表中，用于后续分析

    plt.figure(figsize=(10, 5))
    plt.plot(best_fitness, label='Best Fitness')
    plt.title('Best Fitness Over Generations')
    plt.xlabel('Generation')
    plt.ylabel('Fitness')
    plt.legend()
    plt.grid(True)
    plt.show()

    print("Best Fitness:", best_individual.fitness.values[0])


main()