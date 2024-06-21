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
    
mod = SourceModule("""
__global__ void
fitness_kernel(float *d_successful_demand, float *d_demands, float *d_individual, int *d_paths, int num_paths, int max_path_length, int source, int target) {
    __shared__ float shared_demands[1000]; // 共享内存用于存储路径权重

    int path_idx = threadIdx.x + blockIdx.x * blockDim.x;

    if (path_idx < num_paths) 
    {
        float path_demand = 0.0f;
        float path_failure_prob = 1 - powf(1 - 1/12, (float)(d_paths[path_idx + path_idx + 1] - d_paths[path_idx]));
        float successful_prob = 1 - path_failure_prob;

        // 将d_demands数组加载到共享内存中,以减少内存访问延迟
        for (int i = threadIdx.x; i < 1000; i += blockDim.x) {
            shared_demands[i] = d_demands[source * 1000 + i];
        }
        __syncthreads(); // 等待共享内存加载完成

        for (int i = 0; i < max_path_length; ++i) {
            int node_idx = d_paths[path_idx + path_idx + i];
            if (node_idx == -1) break;
            path_demand += shared_demands[node_idx];
        }
        path_demand *= successful_prob * d_individual[path_idx];

        atomicAdd(d_successful_demand, path_demand);
    }
}
""")

# 获取GPU核函数
fitness_kernel = mod.get_function("fitness_kernel")

def evaluate_on_gpu(individual, demands, paths_dict):
    total_network_demand = sum(demands.values())
    successful_demand = 0

    # 将demand数据转换为numpy数组以便在GPU上处理
    demand_values = np.array(list(demands.values()), dtype=np.float32)

    # 在GPU上分配内存
    d_demands = cuda.to_device(demand_values)
    d_individual = cuda.to_device(np.array(individual, dtype=np.float32))

    # 在循环之外分配内存用于保存计算结果
    d_successful_demand = cuda.mem_alloc(np.dtype(np.float32).itemsize)

    for (source, target), paths in paths_dict.items():
        max_path_length = max(len(path) for path in paths)
        padded_paths = np.full((len(paths), max_path_length), -1, dtype=np.int32)
        for i, path in enumerate(paths):
            padded_paths[i, :len(path)] = path

        # 将路径数据转换为GPU上的数组
        d_paths = cuda.to_device(padded_paths)

        # 配置GPU核函数参数
        block_size = min(256, len(paths))  # 限制每个线程块的线程数量为256
        grid_size = (len(paths) + block_size - 1) // block_size

        # 调用GPU核函数进行路径权重计算
        fitness_kernel(d_successful_demand, d_demands, d_individual, d_paths, np.int32(len(paths)), np.int32(max_path_length), np.int32(source), np.int32(target), block=(block_size, 1, 1), grid=(grid_size, 1))

        # 从GPU上获取计算结果
        h_successful_demand = np.zeros(1, dtype=np.float32)  # 修改这里为正确的大小
        cuda.memcpy_dtoh(h_successful_demand, d_successful_demand)

        successful_demand += h_successful_demand[0]

    # 在循环之外释放内存
    d_successful_demand.free()

    return (successful_demand / total_network_demand,)


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
    toolbox.register("evaluate", evaluate_on_gpu, demands=demands, paths_dict=paths_dict)
    toolbox.register("mate", tools.cxTwoPoint)
    toolbox.register("select", tools.selTournament, tournsize=3)
    toolbox.register("mutate", tools.mutGaussian, mu=0, sigma=0.1, indpb=0.2)
    toolbox.decorate("mutate", checkBounds(0, 1))
    return toolbox

def main():
    # Main function to run the genetic algorithm
    filepath = r'Python/Math/MathClub/51Club/B/data/TDNetwork2.xlsx'
    demands, _ = read_excel_data(filepath)
    G = create_graph()
    paths_dict = {key: generate_k_shortest_paths(G, *key) for key in demands.keys()}
    toolbox = setup_genetic_algorithm(demands, paths_dict)

    population = toolbox.population(n=300)
    NGEN = 40
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
        if gen > 35:
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