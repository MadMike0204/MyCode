import math

def min_fuel_cost(num_stations, distance_per_liter, distances, prices):
    total_cost = 0
    remaining_fuel = 0
    station = 0

    while station < num_stations:
        next_station = station + 1

        # 找到一个价格比当前站点低的站点
        while next_station < num_stations and prices[station] <= prices[next_station]:
            next_station += 1

        # 计算需要行驶的总距离
        total_distance = sum(distances[station:next_station])

        # 计算还需要加多少油
        required_fuel = total_distance / distance_per_liter - remaining_fuel
        if required_fuel > 0:
            fuel_to_buy = math.ceil(required_fuel)
            total_cost += fuel_to_buy * prices[station]
            remaining_fuel = fuel_to_buy - required_fuel
        else:
            remaining_fuel -= required_fuel

        # 移动到下一个加油站
        station = next_station

    return total_cost

# 读取输入
if __name__ == "__main__":
    n, d = map(int, input().split())
    distances = [int(input()) for _ in range(n - 1)]
    prices = [int(input()) for _ in range(n)]

    # 计算最小费用
    result = min_fuel_cost(n, d, distances, prices)
    print(result)
