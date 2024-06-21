import pandas as pd
import pulp

'''
脚本功能:
读取excel表格,提取数据,
读取数据:每对OD的path,每对OD的交通需求 
处理模式:使用pulp包,设置 决策变量 | 目标函数 | 约束条件
处理数据:数据带入设置 的 目标函数
程序结束:把结果输出到excel中
'''
#读取excel表格
def read_excel_data(filepath):
    demands = {}
    demands_dataframe = pd.read_excel(filepath,sheet_name='Demands')
    paths_dataframe = pd.read_excel(filepath, sheet_name='Paths')
    for index, row in demands_dataframe.iterrows():
        start_end_pair = (row['Start'], row['End'])
        demand_value = row['Demand']
        demands[start_end_pair] = demand_value
