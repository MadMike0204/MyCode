import numpy as np
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
from itertools import islice
import random
from scipy.optimize import minimize
from deap import creator, base, tools, algorithms
from scipy.special import comb
from datetime import datetime
import os
from multiprocessing import Pool
from shapely.geometry import Point,LineString,Polygon
from shapely.ops import unary_union

def create_graph():
    # Creating a predefined graph structure
    G = nx.DiGraph()
    edges=[(0,1),(0,3),(0,6),
       (1,0),(1,4),
       (2,3),(2,15),(2,18),
       (3,0),(3,2),(3,36),(3,42),
       (4,1),(4,6),
       (5,6),(5,9),(5,16),(5,22),
       (6,0),(6,4),(6,5),(6,34),(6,36),
       (7,12),(7,24),(7,33),
       (8,9),(8,28),(8,37),(8,41),
       (9,5),(9,8),(9,10), 
       (10,9), (10,11), (10,16), (10,19), (10,41), 
       (11,10), (11,12), (11,20), (11,41),
       (12,7), (12,11), (12,35),
       (13,14), (13,15), (13,38), (13,39),
       (14,13),(14,17),(14,21),
       (15,2),(15,13),(15,42),
       (16,5),(16,10),(16,18),(16,36),
       (17,14),(17,21),(17,39),
       (18,2),(18,16),(18,19),(18,23),
       (19,10),(19,18),(19,20),(19,23),
       (20,11),(20,19),
       (21,14),(21,17),
       (22,5),(22,34),(22,40),
       (23,18),(23,19),
       (24,7),(24,32),
       (25,30),(25,33),
       (26,31),(26,32),(26,33),
       (27,30),(27,33),(27,35),
       (28,8),(28,35),(28,37),
       (29,31),(29,32),
       (30,25),(30,27),
       (31,26),(31,29),
       (32,24),(32,26),(32,29),
       (33,7),(33,25),(33,26),(33,27),
       (34,6),(34,22),(34,40),
       (35,12),(35,27),(35,28),(35,41),
       (36,3),(36,6),(36,16),
       (37,8),(37,28),
       (38,13),(38,39),(38,42),
       (39,13),(39,17),(39,38),
       (40,22),(40,34),
       (41,8),(41,10),(41,11),(41,35),
       (42,3),(42,15),(42,38)]
    G.add_edges_from(edges)
    return G
#获取有向图和无向图
DG = create_graph()
G = DG.to_undirected()
print(G)
#获取坐标字典
filepathP = r'F:\------------------OWN\VSCode\Python\Math\MathClub\51club\B\data\TPoints.xlsx'
df_Points = pd.read_excel(filepathP)
df_Points['Location'] = df_Points['Location'].apply(lambda x: tuple(map(float, x.split(','))))
coordinates = df_Points.set_index('Point')['Location'].to_dict()
#创建LineString对象
lines = {}
for u,v in G.edges():
    lines[(u,v)] = LineString([coordinates[u],coordinates[v]])
#新建路段+相交测试
lines[(2,5)] = LineString([coordinates[2],coordinates[5]])
for (u1, v1), line1 in lines.items():
    for (u2, v2), line2 in lines.items():
        # 确保不比较同一边，同时确保两边没有共同节点
        if {(u1, v1), (v1, u1)} != {(u2, v2), (v2, u2)} and not ({u1, v1} & {u2, v2}):
            if line1.intersects(line2):
                print(f"Edge {(u1, v1)} intersects with edge {(u2, v2)}")
#最外侧的边 测试
boundary_edges = [(1,0),
                (0,3),
                (3,42),
                (42,38),
                (38,39),
                (39,17),
                (17,21),
                (21,14),
                (14,13),
                (13,15),
                (15,2),
                (2,18),
                (18,23),
                (23,19),
                (19,20),
                (20,11),
                (11,12),
                (12,7),
                (7,24),
                (24,32),
                (32,29),
                (29,31),
                (31,26),
                (26,33),
                (33,25),
                (25,30),
                (30,27),
                (27,35),
                (35,28),
                (28,37),
                (37,8),
                (8,9),
                (9,5),
                (5,22),
                (22,40),
                (40,34),
                (34,6),
                (6,4),
                (4,1)]
boundary_polygon = Polygon([coordinates[node] for node, _ in boundary_edges + [boundary_edges[0]]])
#x, y = boundary_polygon.exterior.xy
#fig, ax = plt.subplots()
#ax.fill(x, y, alpha=0.5, fc='lightblue', ec='none')
#nx.draw(G, coordinates, node_color='black', node_size=2, with_labels=True)
#plt.show()
#测试新建路段是否在多边形内
new_lines = LineString([coordinates[21],coordinates[24]])
if new_lines.within(boundary_polygon):
    print("在内部")
else:
    print("不在内部")

#功能测试

def is_valid_new_lines(new_line, boundary_polygon, original_lines):
    # 判断新线段是否完全在边界多边形内
    if not boundary_polygon.contains(new_line):
        return False
    
    # 创建所有原有线段的合集，以便进行相交判断
    if original_lines:
        all_lines_union = unary_union(original_lines)
        # 判断新线段是否与已有线段相交（除了端点外）
        if new_line.intersects(all_lines_union) and not new_line.touches(all_lines_union):
            return False
    
    return True

print(is_valid_new_lines(new_lines,boundary_polygon,lines))
