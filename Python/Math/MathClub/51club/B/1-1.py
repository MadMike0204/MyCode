#
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
import pandas as pd
import os
from itertools import islice

def read_excel_data(filename, sheet_name=0):
    return pd.read_excel(filename,sheet_name=sheet_name)

def create_graph():
    G = nx.Graph()
    edges=[(0,1),(0,3),(0,6),
        (1,0),(1,4),
        (2,3),(2,15),(2,18),
        (3,0),(3,2),(3,36),(3,42),
        (4,0),(4,1),(4,6),
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

def k_shortest_paths(G,source,target,k):
    try:
        return list(islice(nx.shortest_simple_paths(G,source,target),k))
    except nx.NetworkXNoPath:
        return []
def main(input_file,output_file,k = 5):

    data = read_excel_data(input_file)
    G = create_graph()
    results = pd.DataFrame(columns=['Start','End','Path'])

    for index,row in data.iterrows():
        start,end = int(row['Start']),int(row['End'])
        paths = k_shortest_paths(G,start,end,k)
        for path in paths:
            # 将路径列表转换为逗号和空格分隔的字符串
            path_str = ','.join(map(str, path))
            new_row = pd.DataFrame({'Start': [start], 'End': [end], 'Path': [path_str]})
            results = pd.concat([results, new_row], ignore_index=True)

            

    results.to_excel(output_file,index=False)

input_filename = r'Python/Math/MathClub/51Club/B/data/TDNetwork2.xlsx'
output_filename = r'Python/Math/MathClub/51Club/B/output_1.xlsx'

print(os.getcwd())

main(input_filename,output_filename)