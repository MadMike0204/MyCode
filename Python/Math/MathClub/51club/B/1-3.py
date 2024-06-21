import pandas as pd #用于读取附件数据
import numpy as np #用于数学计算
from gurobipy import * #用于建立数学模型和求解

req = pd.read_excel('TDNetwork2.xlsx', sheet_name='交通需求') #读取交通需求数据
req = req.set_index(['Start', 'End']) #将起点和终点设为dataframe的索引值
paths = pd.read_excel('TDNetwork2.xlsx', sheet_name='路径信息') #读取路径信息数据
paths = paths.set_index(['Start', 'End']) #将起点和终点设为dataframe的索引值

模型 = Model('交通需求分配模型') #建立一个名为“交通需求分配模型”的模型
#创建决策变量：每条路径上的交通量
x = {} #创建一个空字典，用于存放决策变量
for i in paths.index: #遍历所有路径
    x[i] = 模型.addVar(vtype=GRB.CONTINUOUS, name='x_'+str(i)) #为每条路径创建变量，并将其添加到模型中
模型.update()

#创建目标函数：最大化期望可达率
目标函数 = 0 #初始化目标函数值
for i in req.index: #遍历所有(起点,终点)对
    for j in paths.loc[i].index: #遍历该(起点,终点)对可以选择的所有路径
        目标函数 += req.loc[i, j] * x[i, j] / req.loc[i].sum() #计算该路径在该(起点,终点)对中的可达率，并加入到目标函数中
模型.setObjective(目标函数, GRB.MAXIMIZE) #设置目标函数为最大化期望可达率

#创建约束条件：每个(起点,终点)对选择的路径数不超过5条
for i in req.index: #遍历所有(起点,终点)对
    模型.addConstr(x.sum(i, '*') <= 5, name='路径数约束_'+str(i)) #创建约束条件，限制每个(起点,终点)对选择的路径数不超过5条

#创建约束条件：每个(起点,终点)对的交通需求满足
for i in req.index: #遍历所有(起点,终点)对
    模型.addConstr(x.sum(i, '*') == req.loc[i].sum(), name='交通需求约束_'+str(i)) #创建约束条件，要求每个(起点,终点)对的交通需求满足

#创建约束条件：每条路径的交通量不能超过路段容量
for i in paths.index: #遍历所有路径
    模型.addConstr(x[i] <= paths.loc[i, '容量'], name='路段容量约束_'+str(i)) #创建约束条件，限制每条路径的交通量不能超过路段容量

模型.optimize() #求解模型

print('最优可达率为：', round(模型.objVal, 2)) #输出最优可达率，保留两位小数
for i in x: #遍历所有决策变量
    if x[i].x > 0: #输出决策变量值大于0的路径及其对应的交通量
        print(i, round(x[i].x, 2))