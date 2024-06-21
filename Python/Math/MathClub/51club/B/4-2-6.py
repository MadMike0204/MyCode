import networkx as nx
from itertools import combinations
from shapely.geometry import LineString, Polygon
import pandas as pd
import networkx as nx
from itertools import combinations
from shapely.geometry import LineString, Polygon
import geopandas as gpd
import pandas as pd
import matplotlib.pyplot as plt

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

def is_valid_new_edge(edge, existing_edges, polygon):
    print(f"Checking edge: {edge}")
    if not edge.within(polygon):
        print("Edge not within polygon.")
        return False
    
    for existing_edge in existing_edges.values():
        # 检查新边是否与任何现有边相交，并确保这种相交不仅仅是在端点上
        if edge.intersects(existing_edge) and not edge.touches(existing_edge):
            return False  # 如果有交叉，且交叉不仅仅是在端点，返回False
    
    print("Edge is valid.")
    a += 1

    return True

def generate_possible_edges(graph, existing_edges, polygon, coordinates):
    nodes = list(graph.nodes())
    candidate_edges = []
    
    # 使用set来快速检查边是否存在
    existing_node_pairs = set((u, v) for u, v in graph.edges()) | set((v, u) for u, v in graph.edges())  # 包括了有向边的两个方向

    for u, v in combinations(nodes, 2):
        if u in coordinates and v in coordinates:
            if (u, v) not in existing_node_pairs and (v, u) not in existing_node_pairs:  # 检查这条边是否已经存在
                pos_u = coordinates[u]
                pos_v = coordinates[v]
                new_edge = LineString([pos_u, pos_v])
                if is_valid_new_edge(new_edge, existing_edges, polygon):
                    candidate_edges.append((u, v))

    return candidate_edges

def generate_edge_combinations(candidate_edges):
    # 生成所有可能的6条边组合，且边不相交
    for combo in combinations(candidate_edges, 6):
        if all(not LineString([coordinates[u], coordinates[v]]).intersects(LineString([coordinates[x], coordinates[y]]))
               for i, (u, v) in enumerate(combo) for j, (x, y) in enumerate(combo) if i < j):
            yield combo

filepathP = r'F:\------------------OWN\VSCode\Python\Math\MathClub\51club\B\data\TPoints.xlsx'
df_Points = pd.read_excel(filepathP)
df_Points['Location'] = df_Points['Location'].apply(lambda x: tuple(map(float, x.split(','))))
coordinates = df_Points.set_index('Point')['Location'].to_dict()

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
    #定义多边形
boundary_polygon = Polygon([coordinates[node] for node, _ in boundary_edges + [boundary_edges[0]]])

DG = create_graph()
G = DG.to_undirected()
existing_edges = {edge: LineString([coordinates[edge[0]], coordinates[edge[1]]]) for edge in G.edges()}
print("Coordinates:")

candidate_edges = generate_possible_edges(G, existing_edges, boundary_polygon, coordinates)

all_combinations = list(generate_edge_combinations(candidate_edges))
print(all_combinations)


rows = []

for index, combo in enumerate(all_combinations):
    row = {}
    for i, edge in enumerate(combo):
        row[f'Edge {i+1}'] = f'{edge[0]}-{edge[1]}'
    rows.append(row)

# 直接从列表创建 DataFrame
df = pd.DataFrame(rows)
# 将 DataFrame 保存到 Excel 文件
excel_path = r'F:\------------------OWN\VSCode\Python\Math\MathClub\51club\B\comb2\combination.xlsx'  # 修改这里为你希望保存文件的路径
df.to_excel(excel_path, index=False)  # index=False 表示不保存行索引到文件中

print("完成")