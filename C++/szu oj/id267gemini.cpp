#include <iostream>
#include <iomanip> // 用于 std::setfill 和 std::setw 来格式化输出

// 前向声明 Work 类，因为 operator<< 和 before 函数的参数需要它
class Work;

// 1. 定义一个日期类Date
class Date {
protected:
    int year;
    int month;
    int day;
public:
    // Date 类的构造函数: 初始化年月日
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
};

// 2. 定义一个时间类Time
class Time {
protected:
    int hour;
    int minute;
    int second; // 题目描述中提到“12小时制”，但未提供AM/PM信息，按直接数值比较处理
public:
    // Time 类的构造函数: 初始化时分秒
    Time(int h = 0, int min_val = 0, int s_val = 0) : hour(h), minute(min_val), second(s_val) {}
};

// 3. 以Date类和Time类为基类，创建一个作业类Work
class Work : public Date, public Time {
private:
    int ID; // 作业的ID
public:
    // Work 类的构造函数: 初始化ID及基类的日期和时间成员
    Work(int id_val = 0, int y = 0, int m = 0, int d = 0, int h = 0, int min_val = 0, int s_val = 0)
        : ID(id_val), Date(y, m, d), Time(h, min_val, s_val) {}

    // 友元函数声明
    // 声明 bool before(const Work& w1, const Work& w2) 为友元函数
    friend bool before(const Work& w1, const Work& w2);
    // 声明输出运算符 << 为友元函数，方便格式化输出Work对象
    friend std::ostream& operator<<(std::ostream& os, const Work& w);
};

// 4. 定义一个友元函数 bool before(const Work& w1, const Work& w2)
// 功能：判断作业w1的时间是否严格早于作业w2的时间
bool before(const Work& w1, const Work& w2) {
    if (w1.year < w2.year) return true;
    if (w1.year > w2.year) return false;
    // 年份相同，比较月份
    if (w1.month < w2.month) return true;
    if (w1.month > w2.month) return false;
    // 月份相同，比较日期
    if (w1.day < w2.day) return true;
    if (w1.day > w2.day) return false;
    // 日期相同，比较小时
    if (w1.hour < w2.hour) return true;
    if (w1.hour > w2.hour) return false;
    // 小时相同，比较分钟
    if (w1.minute < w2.minute) return true;
    if (w1.minute > w2.minute) return false;
    // 分钟相同，比较秒钟
    if (w1.second < w2.second) return true;
    // 如果w1不早于w2（即w1等于w2或w1晚于w2），则返回false
    return false;
}

// 重载输出运算符 <<
// 功能：用于按指定格式输出Work对象的信息
std::ostream& operator<<(std::ostream& os, const Work& w) {
    // 输出格式: The urgent Work is No.ID: YYYY/MM/DD HH:MM:SS
    os << "The urgent Work is No." << w.ID << ": "
       << w.year << "/"
       << std::setfill('0') << std::setw(2) << w.month << "/"
       << std::setfill('0') << std::setw(2) << w.day << " "
       << std::setfill('0') << std::setw(2) << w.hour << ":"
       << std::setfill('0') << std::setw(2) << w.minute << ":"
       << std::setfill('0') << std::setw(2) << w.second;
    return os;
}

// 主函数
// 功能：读取若干作业信息，找出截止日期最早的作业并按指定格式输出
int main() {
    // 优化输入输出效率 (可选)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int id_val, y, m, d, h, min_val, s_val;
    Work mostUrgentWork;
    bool hasProcessedWork = false; // 标记是否已处理过至少一个有效作业

    // 循环读取作业信息
    // 当输入ID为0时结束
    while (std::cin >> id_val && id_val != 0) {
        std::cin >> y >> m >> d >> h >> min_val >> s_val;
        Work currentWork(id_val, y, m, d, h, min_val, s_val);

        // 如果是第一个有效作业，或者当前作业比记录的最紧急作业更早
        if (!hasProcessedWork || before(currentWork, mostUrgentWork)) {
            mostUrgentWork = currentWork;
            hasProcessedWork = true;
        }
    }

    // 如果处理过有效作业，则输出最紧急的作业
    if (hasProcessedWork) {
        std::cout << mostUrgentWork << std::endl;
    }

    return 0;
}
