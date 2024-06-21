import pandas as pd
import numpy as np
from gurobipy import *

# 读取数据
req = pd.read_excel('TDNetwork2.xlsx', sheet_name='交通需求')
req = req.set_index(['Start', 'End'])
paths = pd.read_excel('TDNetwork2.xlsx', sheet_name='路径信息')
paths = paths.set_index(['Start', 'End'])

# 创建模型
模型 = Model('交通需求分配模型')

# 创建决策变量：每条路径上的交通量
x = {}
for i in paths.index:
    x[i] = 模型.addVar(vtype=GRB.CONTINUOUS, name='x_' + str(i))
模型.update()

# 创建目标函数：最大化期望可达率
目标函数 = quicksum(req.loc[i, '需求'] * x[i] / req.loc[i].sum() for i in paths.index)
模型.setObjective(目标函数, GRB.MAXIMIZE)

# 创建约束条件
# 约束：每个(起点,终点)对选择的路径数不超过5条
for i in req.index.unique():
    模型.addConstr(quicksum(x[j] for j in paths.loc[i].index if j in x) <= 5, name='路径数约束_' + str(i))

# 约束：每个(起点,终点)对的交通需求满足
for i in req.index.unique():
    模型.addConstr(quicksum(x[j] for j in paths.loc[i].index if j in x) == req.loc[i, '需求'].sum(), name='交通需求约束_' + str(i))

# 求解模型
模型.optimize()

# 输出结果
if 模型.status == GRB.OPTIMAL:
    print('最优可达率为：', round(模型.objVal, 2))
    for i in x:
        if x[i].X > 0:
            print(i, round(x[i].X, 2))