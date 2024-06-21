import numpy as np
from scipy.spatial import Delaunay
import networkx as nx
import matplotlib.pyplot as plt

B_points = np.array(
    [[0,0],[80,0],[80,50],[0,50]],dtype="int"
)
A_points = np.array(
    [[20,15],[60,15],[60,35],[20,35]],dtype="int"
)
AllPoints = np.concatenate((A_points,B_points),axis = 0)

tri = Delaunay(AllPoints)

myGraph = nx.Graph()
edges = set()
#根据三角剖分结果添加边
for simplex in tri.simplices:
    for i in range(3):
        edge = (simplex[i],simplex[(i+1)%3])
        edges.add(tuple(sorted(edge)))
#向图中添加边和权重
for edge in edges:
    u,v = edge
    weight = np.linalg.norm(AllPoints[u] - AllPoints[v])
    myGraph.add_edge(u,v,weight=weight)

#寻找最小生成树
mst = nx.minimum_spanning_tree(myGraph)

odd_degree_nodes = [node for node in mst.nodes() if mst.degree(node)]
odd_subgraph = mst.subgraph(odd_degree_nodes)

for u,v,data in odd_subgraph.edges(data=True):
    data['weight'] *= -1

min_cost_perfect_matching = nx.algorithms.matching.max_weight_matching(
    odd_subgraph,maxcardinality=True,weight='weight'
)

mst.add_edges_from(min_cost_perfect_matching)

print("匹配的边：",min_cost_perfect_matching)

pos = nx.spring_layout(mst)
nx.draw(mst,pos,with_labels=True,node_color='lightblue')
nx.draw_networkx_edges(mst,pos,edgelist=min_cost_perfect_matching,edge_color='red',width=2)
plt.show()

myGraph.add_edges_from(min_cost_perfect_matching)
eulerian_circuit = list(nx.eulerian_circuit(myGraph))

pos = {i:p for i,p in enumerate(AllPoints)}
nx.draw(myGraph,pos,with_labels=True,node_color='black')
plt.show()