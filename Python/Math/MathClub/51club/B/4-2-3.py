import json
import os
from itertools import combinations
from shapely.geometry import LineString, Polygon
from shapely.ops import unary_union
import networkx as nx
import pandas as pd

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

def create_union_of_lines(original_lines):
    lines_list = list(original_lines.values())
    return unary_union(lines_list) if lines_list else None

def is_valid_new_lines(new_line, boundary_polygon, all_lines_union):
    if not boundary_polygon.contains(new_line):
        return False
    if all_lines_union and new_line.intersects(all_lines_union) and not new_line.touches(all_lines_union):
        return False
    return True

def is_valid_combination(combination, coordinates):
    # 创建组内所有路段的 LineString 对象
    line_strings = [LineString([coordinates[start], coordinates[end]]) for start, end in combination]
    # 检查每条路段是否与组内其他路段相交（不包括共端点相交）
    for i in range(len(line_strings)):
        for j in range(i + 1, len(line_strings)):
            if line_strings[i].intersects(line_strings[j]) and not line_strings[i].touches(line_strings[j]):
                return False
    return True

def process_all_combinations(all_combinations, original_lines, boundary_polygon, coordinates):
    all_lines_union = create_union_of_lines(original_lines)
    results = []
    for combo in all_combinations:
        result = process_single_combination(combo, original_lines, boundary_polygon, coordinates, all_lines_union)
        if result is not None:
            results.append(result)
    return results

def process_single_combination(combination, original_lines, boundary_polygon, coordinates, all_lines_union):
    new_line = LineString([coordinates[combination[0]], coordinates[combination[1]]])
    if is_valid_new_lines(new_line, boundary_polygon, all_lines_union):
        return combination
    return None

def generate_six_combinations(valid_combinations, coordinates):
    six_combinations = combinations(valid_combinations, 6)
    valid_six_combinations = [combo for combo in six_combinations if is_valid_combination(combo, coordinates)]
    return valid_six_combinations


def save_combinations_to_excel(six_combinations, file_path):
    # 创建DataFrame
    data = {"Combination": [",".join(map(str, combo)) for combo in six_combinations]}
    df = pd.DataFrame(data)
    
    # 将DataFrame保存到Excel文件
    with pd.ExcelWriter(file_path, engine='xlsxwriter') as writer:
        df.to_excel(writer, index=False, sheet_name='Combinations')

def main():
    filepathP = r'F:\------------------OWN\VSCode\Python\Math\MathClub\51club\B\data\TPoints.xlsx'
    df_Points = pd.read_excel(filepathP)
    df_Points['Location'] = df_Points['Location'].apply(lambda x: tuple(map(float, x.split(','))))
    coordinates = df_Points.set_index('Point')['Location'].to_dict()
    #多边形边缘
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
    #现有路段
    DG = create_graph()
    G = DG.to_undirected()
    lines = {}
    for u,v in G.edges():
        lines[(u,v)] = LineString([coordinates[u],coordinates[v]])
    # 省略数据加载和图形创建代码，保留主逻辑
    all_possible_combinations = list(combinations(coordinates.keys(), 2))
    valid_combinations = process_all_combinations(all_possible_combinations, lines, boundary_polygon, coordinates)
    six_combinations = generate_six_combinations(valid_combinations,coordinates)
    excel_file_path = r'F:\------------------OWN\VSCode\Python\Math\MathClub\51club\B\comb2\combinations.xlsx'
    save_combinations_to_excel(six_combinations, excel_file_path)

if __name__ == '__main__':
    main()
