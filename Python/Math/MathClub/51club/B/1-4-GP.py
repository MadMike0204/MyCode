import numpy as np
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
from itertools import islice
import random
from scipy.optimize import minimize
from deap import creator, base, tools, algorithms

def read_excel_data(filepath):

    demands = {}
    demands_dataframe = pd.read_excel(filepath,sheet_name='Demands')
    for index, row in demands_dataframe.iterrows():
        origin_destination = (row['Start'], row['End'])
        demand_value = row['Demand']
        demands[origin_destination] = demand_value * 1.0
    return demands

def create_graph():
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
    """ 生成从source到target的所有简单路径 """
    return list(nx.all_simple_paths(G, source=source, target=target, cutoff=cutoff))

def k_shortest_paths(G,source,target,k=5):
    try:
        return list(islice(nx.shortest_simple_paths(G,source,target),k))
    except nx.NetworkXNoPath:
        return []

#适应度函数
def evaluate(individual, G, demands, paths_dict):
    total_network_demand = sum(demands.values())
    successful_demand = 0

    for (source, target), paths in paths_dict.items():
        path_weights = individual[:len(paths)]  # 获取对应路径的权重
        individual = individual[len(paths):]  # 修剪已处理的权重
        normalized_weights = np.clip(path_weights, 0, 1)  # 限制权重在[0, 1]范围内
        normalized_weights /= np.sum(normalized_weights)  # 归一化以保证总和为1

        for path in paths:
            path_failure_prob = 1 - (1 - 1/12) ** (len(path) - 1)  # 计算路径故障的概率
            successful_prob = 1 - path_failure_prob
            path_demand = demands[(source, target)] * successful_prob * normalized_weights
            successful_demand += np.sum(path_demand)

    return (successful_demand / total_network_demand,)

#限制变异操作
def checkBounds(min, max):
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
# 数据准备
G = create_graph()
filepath = r'Python/Math/MathClub/51Club/B//data/TDNetwork2.xlsx'
demands = read_excel_data(filepath)

# 遗传算法配置
creator.create("FitnessMax", base.Fitness, weights=(1.0,))
creator.create("Individual", list, fitness=creator.FitnessMax)

toolbox = base.Toolbox()
toolbox.register("attr_float", random.random)
toolbox.register("individual", tools.initRepeat, creator.Individual,
                 toolbox.attr_float, n=180)  # 需根据实际路径数调整
toolbox.register("population", tools.initRepeat, list, toolbox.individual)
toolbox.register("evaluate", evaluate, G=create_graph(), demands=read_excel_data(r'Python/Math/MathClub/51Club/B//data/TDNetwork2.xlsx'),
                 paths_dict={key: generate_all_paths(G, *key) for key in demands.keys()})
toolbox.register("mate", tools.cxTwoPoint)
toolbox.register("select", tools.selTournament, tournsize=3)

toolbox.register("mutate", tools.mutGaussian,mu=0, sigma=0.1, indpb=0.2)
toolbox.decorate("mutate", checkBounds(0, 1))  # 确保变异后的基因在[0, 1]范围内

#遗传算法实现
def main():
    population = toolbox.population(n=300)
    NGEN = 50
    best_fitness = []

    for gen in range(NGEN):
        offspring = algorithms.varAnd(population, toolbox, cxpb=0.5, mutpb=0.2)
        fits = map(toolbox.evaluate, offspring)
        for fit, ind in zip(fits, offspring):
            ind.fitness.values = fit

        population = toolbox.select(offspring, k=len(population))
        best_individual = tools.selBest(population, k=1)[0]
        best_fitness.append(best_individual.fitness.values[0])

    print("Best Fitness:", best_individual.fitness.values[0])
    
if __name__ == "__main__":
    main()