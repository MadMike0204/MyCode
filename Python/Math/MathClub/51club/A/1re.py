import numpy as np
from scipy.spatial import Delaunay
import networkx as nx
import matplotlib.pyplot as plt

# 点坐标定义
B_points = np.array([[0, 0], [80, 0], [80, 50], [0, 50]], dtype="int")
A_points = np.array([[20, 15], [60, 15], [60, 35], [20, 35]], dtype="int")
AllPoints = np.concatenate((A_points, B_points), axis=0)

# Delaunay三角剖分
tri = Delaunay(AllPoints)

# 创建图并添加边和权重
myGraph = nx.Graph()
edges = set()
for simplex in tri.simplices:
    for i in range(3):
        edge = (simplex[i], simplex[(i+1)%3])
        edges.add(tuple(sorted(edge)))
for edge in edges:
    u, v = edge
    weight = np.linalg.norm(AllPoints[u] - AllPoints[v])
    myGraph.add_edge(u, v, weight=weight)

# 最小生成树和完美匹配
mst = nx.minimum_spanning_tree(myGraph)
odd_degree_nodes = [node for node in mst.nodes() if mst.degree(node) % 2 == 1]
odd_subgraph = mst.subgraph(odd_degree_nodes)
for u, v, data in odd_subgraph.edges(data=True):
    data['weight'] *= -1

min_cost_perfect_matching = nx.algorithms.matching.max_weight_matching(
    odd_subgraph, maxcardinality=True, weight='weight'
)

# 添加完美匹配边到原图
myGraph.add_edges_from(min_cost_perfect_matching)
mst.add_edges_from(min_cost_perfect_matching)

# 确认图是否为欧拉图
all_even = all(deg % 2 == 0 for node, deg in myGraph.degree())
if all_even:
    eulerian_circuit = list(nx.eulerian_circuit(myGraph))
    pos = {i: p for i, p in enumerate(AllPoints)}
    nx.draw(myGraph, pos, with_labels=True, node_color='black')
    plt.show()
else:
    print("当前图不是欧拉图，无法生成欧拉回路。")


# 打印出图中每个顶点的度数
for node in myGraph.nodes():
    print(f"顶点 {node} 的度数为：{myGraph.degree(node)}")

# 检查并打印是否每个顶点的度数都是偶数
if all(myGraph.degree(node) % 2 == 0 for node in myGraph.nodes()):
    print("所有顶点的度数都是偶数，图是欧拉图。")
else:
    print("存在顶点的度数为奇数，图不是欧拉图。")
