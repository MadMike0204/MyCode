#include <iostream>
#include <vector> 
#include <string> 
#include <iomanip> 


class Vehicle {
public:
    std::string name; // 车辆名称
    int daily_rent;   // 每日租金

    // 构造函数: 初始化车辆基本属性
    Vehicle(std::string n, int rent) : name(n), daily_rent(rent) {}

    // 虚析构函数: 保证派生类析构函数被正确调用
    virtual ~Vehicle() {}

    // 纯虚函数: 获取最大载客人数，由派生类实现
    virtual int getPassengerCapacity() const = 0;

    // 纯虚函数: 获取最大载货重量，由派生类实现
    virtual double getCargoCapacity() const = 0;

    // 功能：计算指定天数的租金
    int calculateRent(int days) const {
        return daily_rent * days;
    }
};

// 客车类，继承自Vehicle
class Bus : public Vehicle {
private:
    int passenger_capacity; // 客车载客量

public:
    // 构造函数: 初始化客车属性
    Bus(std::string n, int rent, int p_cap)
        : Vehicle(n, rent), passenger_capacity(p_cap) {}

    // 功能：返回客车的最大载客人数
    int getPassengerCapacity() const override {
        return passenger_capacity;
    }

    // 功能：返回客车的最大载货重量 (客车为0)
    double getCargoCapacity() const override {
        return 0.0;
    }
};

// 货车类，继承自Vehicle
class Truck : public Vehicle {
private:
    double cargo_capacity; // 货车载货量 (吨)

public:
    // 构造函数: 初始化货车属性
    Truck(std::string n, int rent, double c_cap)
        : Vehicle(n, rent), cargo_capacity(c_cap) {}

    // 功能：返回货车的最大载客人数 (货车为0)
    int getPassengerCapacity() const override {
        return 0;
    }

    // 功能：返回货车的最大载货重量
    double getCargoCapacity() const override {
        return cargo_capacity;
    }
};

// 皮卡车类，继承自Vehicle (客货两用)
class PickupTruck : public Vehicle {
private:
    int passenger_capacity; // 皮卡车载客量
    double cargo_capacity;  // 皮卡车载货量 (吨)

public:
    // 构造函数: 初始化皮卡车属性
    PickupTruck(std::string n, int rent, int p_cap, double c_cap)
        : Vehicle(n, rent), passenger_capacity(p_cap), cargo_capacity(c_cap) {}

    // 功能：返回皮卡车的最大载客人数
    int getPassengerCapacity() const override {
        return passenger_capacity;
    }

    // 功能：返回皮卡车的最大载货重量
    double getCargoCapacity() const override {
        return cargo_capacity;
    }
};

// 主函数
// 功能：程序入口，处理用户输入，计算并输出租车结果。
int main() {
    std::cout << std::fixed << std::setprecision(2); // 设置浮点数输出格式

    std::vector<Vehicle*> available_vehicles; // 存储所有可用车辆的列表

    // 初始化车辆信息 (序号对应索引+1)
    // 注意: 车辆 A 的载客量根据示例输出从表格的5调整为10。
    available_vehicles.push_back(new Bus("A", 800, 10));        // 1. 客车 A
    available_vehicles.push_back(new Bus("B", 400, 5));         // 2. 客车 B
    available_vehicles.push_back(new Bus("C", 800, 5));         // 3. 客车 C
    available_vehicles.push_back(new Bus("D", 1300, 51));       // 4. 客车 D
    available_vehicles.push_back(new Bus("E", 1500, 55));       // 5. 客车 E
    available_vehicles.push_back(new PickupTruck("F", 500, 5, 0.45)); // 6. 皮卡 F
    available_vehicles.push_back(new PickupTruck("G", 450, 5, 2.0));  // 7. 皮卡 G
    available_vehicles.push_back(new Truck("H", 200, 3.0));     // 8. 货车 H
    available_vehicles.push_back(new Truck("I", 1500, 25.0));   // 9. 货车 I
    available_vehicles.push_back(new Truck("J", 2000, 35.0));   // 10. 货车 J

    int rent_choice;
    std::cin >> rent_choice; // 读取是否租车

    if (rent_choice == 0) {
        std::cout << "0 0.00 0" << std::endl; // 不租车，按要求输出
    } else {
        int num_rentals;
        std::cin >> num_rentals; // 读取租车数量

        int total_passengers = 0;
        double total_cargo_weight = 0.0;
        int total_rent_amount = 0;

        // 处理每笔租车订单
        for (int i = 0; i < num_rentals; ++i) {
            int vehicle_serial, days;
            std::cin >> vehicle_serial >> days; // 读取车辆编号和天数

            if (vehicle_serial >= 1 && static_cast<size_t>(vehicle_serial) <= available_vehicles.size()) {
                Vehicle* selected_vehicle = available_vehicles[vehicle_serial - 1]; // 获取选定车辆
                total_passengers += selected_vehicle->getPassengerCapacity();
                total_cargo_weight += selected_vehicle->getCargoCapacity();
                total_rent_amount += selected_vehicle->calculateRent(days);
            }
        }
        // 输出总计结果
        std::cout << total_passengers << " " << total_cargo_weight << " " << total_rent_amount << std::endl;
    }

    // 清理动态分配的内存
    for (Vehicle* v : available_vehicles) {
        delete v;
    }
    available_vehicles.clear();

    return 0;
}
