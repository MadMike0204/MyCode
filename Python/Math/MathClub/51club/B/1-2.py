import pandas as pd
import pulp
# 读取Excel文件
def read_excel_data(filepath):
    demands_df = pd.read_excel(filepath, sheet_name='Demands')
    paths_df = pd.read_excel(filepath, sheet_name='Paths')

    # 转换demands到字典
    demands = {(row['Start'], row['End']): row['Demand'] for index, row in demands_df.iterrows()}

    # 转换paths到字典，每个键是起点到终点的元组，值是路径列表
    paths = {}
    for index, row in paths_df.iterrows():
        key = (row['Start'], row['End'])
        if key not in paths:
            paths[key] = []
        paths[key].append(row['Path'].split(','))  # 假设路径中的节点由逗号分隔

    return demands, paths

def calculate_path_reliability(path, uniform_prob):
    prob = 1.0
    for i in range(len(path) - 1):
        prob *= (1.0 - uniform_prob)
    return prob

def main(filepath,closure_possibility):
    demands, paths = read_excel_data(filepath)
    problem = pulp.LpProblem("Maximize_Expected_Reachability",pulp.LpMaximize)

    #决策变量
    traffic_vars = {}
    for od, path_list in paths.items():
        for path in path_list:
            var_name = f"Traffic_{od}_{tuple(path)}"
            traffic_vars[(od, tuple(path))] = pulp.LpVariable(var_name, lowBound=0,cat='Continuous')
    #约束
    for od,od_paths in paths.items():
        problem += pulp.lpSum([traffic_vars[(od,tuple(path))] for path in od_paths]) == demands[od],f"Demand_Constraint_{od}"
    #目标函数
    for od,od_paths in paths.items():
        for path in od_paths:
            reliability = calculate_path_reliability(path,closure_possibility)
            problem += pulp.lpSum([traffic_vars[(od,tuple(path))] * reliability])
    
    problem.solve()

    # 检查问题是否正确解决
    if problem.status == pulp.LpStatusOptimal:
        print("Optimal solution found.")
        for v in problem.variables():
            print(v.name, "=", v.varValue)
    else:
        print("No optimal solution found. Status:", pulp.LpStatus[problem.status])

#------------------------预设----------------------------
filepath = r'Python/Math/MathClub/51Club/B/TDN2.xlsx'
closure_possibility = 0.2

main(filepath,closure_possibility)



