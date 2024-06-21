import pandas as pd
import networkx as nx
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

def add_attributes_to_graph(G, edge_data):
    for (start, end), attributes in edge_data.items():
        if G.has_edge(start, end):
            G[start][end].update(attributes)

def extract_edge_demands(data):
    edge_demands = {}
    for index, row in data.iterrows():
        path_list = eval(row['Path'])  # 解析路径为列表
        demand = row['Assigned Demand']
        for i in range(len(path_list) - 1):
            edge = (path_list[i], path_list[i+1])
            if edge in edge_demands:
                edge_demands[edge] += demand
            else:
                edge_demands[edge] = demand
    return {edge: {'Total Demand': demand} for edge, demand in edge_demands.items()}

def add_utilization_percentage_to_graph(G):
    for u, v in G.edges():
        if 'Total Demand' in G[u][v] and 'Capacity' in G[u][v]:
            total_demand = G[u][v]['Total Demand']
            capacity = G[u][v]['Capacity']
            if capacity > 0:  # 避免除以零
                utilization = (total_demand / capacity) * 100
                G[u][v]['Utilization Percentage'] = utilization
            else:
                G[u][v]['Utilization Percentage'] = 0  # 如果容量为0，设置为0%

def load_capacity_data(data):
    capacity_dict = {}
    for index, row in data.iterrows():
        capacity_dict[(row['Start'], row['End'])] = {'Capacity': row['Capacity']}
    return capacity_dict



def create_colored_graph(G):
    # 设置图形大小
    plt.figure(figsize=(12, 12))
    
    # 节点位置
    pos = nx.kamada_kawai_layout(G)  # 使用Spring布局

    # 根据占用百分比为每条边选择颜色
    edge_colors = []
    for u, v, data in G.edges(data=True):
        utilization = data.get('Utilization Percentage', 0)
        if utilization > 100:
            edge_colors.append('red')  # 超载
        elif utilization > 70:
            edge_colors.append('orange')
        elif utilization > 40:
            edge_colors.append('yellow')  # 中等占用
        else:
            edge_colors.append('green')  # 低占用

    # 绘制节点
    nx.draw_networkx_nodes(G, pos, node_size=700, node_color='blue', alpha=0.6)

    # 绘制边
    nx.draw_networkx_edges(G, pos, arrowstyle='-|>', arrowsize=20, edge_color=edge_colors, width=2)

    # 标签
    nx.draw_networkx_labels(G, pos, font_size=12, font_family='sans-serif')

    # 显示图形
    plt.title('Road Utilization Graph')
    plt.axis('off')  # 关闭坐标轴
    plt.show()
def main():

    file_path1 = r'F:\------------------OWN\VSCode\Python\Math\MathClub\51club\B\data\LCNetwork3.xlsx'
    file_path2 = r'F:\------------------OWN\VSCode\Python\Math\MathClub\51club\B\data\already.xlsx'
    # 尝试加载数据并显示前几行以检查数据结构
    capacity_data = pd.read_excel(file_path1)
    traffic_data = pd.read_excel(file_path2)
    print(capacity_data.head(n=5))
    print(traffic_data.head(n=5))
    edge_demands = extract_edge_demands(traffic_data)
    capacity_info = load_capacity_data(capacity_data)
    G = create_graph()
    add_attributes_to_graph(G, edge_demands)
    add_attributes_to_graph(G, capacity_info)

    add_utilization_percentage_to_graph(G)

    create_colored_graph(G)

    for u, v, data in G.edges(data=True):
        total_demand = data.get('Total Demand', 'N/A')
        capacity = data.get('Capacity', 'N/A')
        utilization = data.get('Utilization Percentage', 'N/A')
        print(f"({u}, {v}) | {total_demand} | {capacity} | {utilization:.2f}%")
    create_colored_graph(G)

if __name__ == '__main__':
    main()