import pandas as pd
import numpy as np
from gurobipy import *

# 读取数据
paths = pd.read_excel('TDNetwork2.xlsx', sheet_name='路径信息')
paths = paths.set_index(['Start', 'End'])
req = pd.read_excel('TDNetwork2.xlsx', sheet_name='交通需求')
req = req.set_index(['Start', 'End'])

# 初始化模型
model = Model('Traffic Distribution Model')

# 创建变量
x = model.addVars(paths.index, vtype=GRB.CONTINUOUS, name="Flow")

# 设置目标函数
model.setObjective(sum(req.loc[i, 'Demand'] * x[i] / req.loc[i].sum() for i in paths.index), GRB.MAXIMIZE)

# 添加需求满足约束
for i in req.index:
    model.addConstr(sum(x[j] for j in paths.loc[i].index) == req.loc[i, 'Demand'], name=f"Demand_{i}")

# 求解模型
model.optimize()

# 输出结果
if model.status == GRB.OPTIMAL:
    print('Optimal Reachability:', model.objVal)
    for v in model.getVars():
        if v.x > 0:
            print(f"{v.varName}: {v.x}")
