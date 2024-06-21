from itertools import combinations
from shapely.geometry import LineString, Polygon
from shapely.ops import unary_union
import networkx as nx
import pandas as pd
from multiprocessing import Pool

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
    return unary_union(list(original_lines.values())) if original_lines else None

def is_valid_new_line(new_line, boundary_polygon, all_lines_union):
    if not boundary_polygon.contains(new_line):
        return False
    if all_lines_union and new_line.intersects(all_lines_union) and not new_line.touches(all_lines_union):
        return False
    return True

def is_valid_combination(combination, coordinates, boundary_polygon, all_lines_union):
    line_strings = [LineString([coordinates[start], coordinates[end]]) for start, end in combination]
    # 判断组内路段是否互不相交
    for i in range(len(line_strings)):
        if not is_valid_new_line(line_strings[i], boundary_polygon, all_lines_union):
            return False
        for j in range(i + 1, len(line_strings)):
            if line_strings[i].intersects(line_strings[j]) and not line_strings[i].touches(line_strings[j]):
                return False
    return True

def process_all_combinations_parallel(all_combinations, original_lines, boundary_polygon, coordinates, batch_size=1000):
    all_lines_union = create_union_of_lines(original_lines)
    # 准备参数，每个参数是一个包含全部必要信息的元组
    combo_args = [(combo, original_lines, boundary_polygon, coordinates, all_lines_union) for combo in all_combinations]

    with Pool() as pool:
        results = []
        for i in range(0, len(combo_args), batch_size):
            # 注意这里的调用，我们传递的是一个元组的列表
            batch_results = pool.starmap(process_single_combination, combo_args[i:i + batch_size])
            # 过滤 None 结果，并展平结果
            valid_results = [result for result in batch_results if result is not None]
            results.extend(valid_results)
    return results

def process_single_combination(args):
    # 展开参数
    combination, original_lines, boundary_polygon, coordinates, all_lines_union = args
    new_line = LineString([coordinates[combination[0]], coordinates[combination[1]]])
    if is_valid_new_line(new_line, boundary_polygon, all_lines_union):
        return combination
    return None


def save_combinations_to_excel(combination_batch, file_path):
    data = {"Combination": [",".join(map(str, combo)) for combo in combination_batch]}
    df = pd.DataFrame(data)
    df.to_excel(file_path, index=False)

def main():
    #获得点
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
        # 创建图和原有路段的集合
    DG = create_graph()
    G = DG.to_undirected()
    original_lines = {(u, v): LineString([coordinates[u], coordinates[v]]) for u, v in G.edges()}

    # 获取所有可能的两点组合
    all_possible_combinations = list(combinations(coordinates.keys(), 2))

    # 处理所有组合，生成有效的六点组合
    final_combinations = process_all_combinations_parallel(all_possible_combinations, original_lines, boundary_polygon, coordinates)

    # 保存到Excel
    if final_combinations:
        save_combinations_to_excel(final_combinations, r'F:\------------------OWN\VSCode\Python\Math\MathClub\51club\B\final_combinations.xlsx')
    else:
        print("No valid combinations found.")


if __name__ == '__main__':
    main()