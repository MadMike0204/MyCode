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

def simulate_network(G, source_target_demands, num_simulations=1000):
    success_rates = []

    for _ in range(num_simulations):
        successful_demand = 0
        total_network_demand = sum(source_target_demands.values())  # 网络总需求

        for (source, target), demand in source_target_demands.items():
            paths = k_shortest_paths(G, source, target)  # 获取k个最短路径
            # 使用Dirichlet分布直接生成满足总和为1的随机数，然后乘以总需求量
            path_demands = np.random.dirichlet(np.ones(len(paths))) * demand

            for path, path_demand in zip(paths, path_demands):
                if all(random.random() >= 1/12 for _ in path[:-1]):  # 检查每条路径上的边是否未中断
                    successful_demand += path_demand

        success_rate = successful_demand / total_network_demand if total_network_demand > 0 else 0
        success_rates.append(success_rate)

    return np.mean(success_rates) * 100  # 返回平均成功率的百分比形式

# 数据准备
G = create_graph()
filepath = r'Python/Math/MathClub/51Club/B//data/TDNetwork2.xlsx'
demands = read_excel_data(filepath)

# 模拟交通测试
average_success_rate = simulate_network(G, demands)
print(f"Average success rate: {average_success_rate:.2f}%")
