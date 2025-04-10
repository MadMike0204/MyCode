#include <iostream>
#include <cmath>
#include <vector> // 建议使用 vector 代替原始指针数组

using namespace std;

class Point {
	double x, y;  //x和y坐标
public:
	Point();  //缺省构造函数，设x和y坐标为0
	Point(double x_value, double y_value); //有参构造
	double getX();	//返回x的值
	double getY();	//返回y的值 // 修正注释，应该是 y
	void setXY(double x1, double y1);
	void setX(double x_value); // 注意这里参数名和成员变量名大小写不同
	void setY(double y_value); // 注意这里参数名和成员变量名大小写不同
	double getDisTo(Point &p);
};

class Circle {
	Point centre; //圆心
	double radius;	//半径
public:
	Circle();	//设置圆心位置为(0，0)，半径为1
	Circle(double x, double y, double r);	//有参构造，设置圆心和半径
	void moveCentreTo(double x1, double y1);	//圆心位置移动到(x1，y1)
	int contain(Point &p);	//判断圆与点p的关系，如果点p在圆内则返回1，否则返回0
};
//下面完成两个类的类定义和主函数
/********** Write your code here! **********/

// Point 类成员函数实现
Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(double x_value, double y_value) {
    x = x_value;
    y = y_value;
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

void Point::setXY(double x1, double y1) {
    x = x1;
    y = y1;
}

void Point::setX(double x_value) {
    x = x_value;
}

void Point::setY(double y_value) {
    y = y_value;
}

// 计算当前点到点 p 的距离
double Point::getDisTo(Point &p) {
    double dx = x - p.getX(); // 使用 getX() 获取 p 的 x 坐标
    double dy = y - p.getY(); // 使用 getY() 获取 p 的 y 坐标
    return sqrt(dx * dx + dy * dy);
}

// Circle 类成员函数实现
Circle::Circle() {
    centre.setXY(0.0, 0.0); // 使用 Point 的 setXY 方法设置圆心
    radius = 1.0;
}

Circle::Circle(double x, double y, double r) {
    centre.setXY(x, y); // 使用 Point 的 setXY 方法设置圆心
    radius = r;
}

void Circle::moveCentreTo(double x1, double y1) {
    centre.setXY(x1, y1); // 使用 Point 的 setXY 方法移动圆心
}

// 判断点 p 是否在圆内
// 点在圆内或圆上返回 1，否则（圆外）返回 0
int Circle::contain(Point &p) {
    double distance = centre.getDisTo(p); // 计算点 p 到圆心的距离
    // 修改判断条件，包含等于的情况 (点在圆上)
    if (distance <= radius) {
        return 1; // 点在圆内或圆上
    } else {
        return 0; // 点在圆外
    }
}



// 主函数
int main() {
    double x, y, r;
    // 读取圆的初始信息
    cin >> x >> y >> r;
    Circle myCircle(x, y, r);

    int n;
    // 读取点的数量
    cin >> n;

    // 使用原始指针和 new 来动态分配 Point 数组
    Point* points = new Point[n];

    // 读取并初始化 Point 对象
    for (int i = 0; i < n; ++i) {
        double px, py;
        cin >> px >> py;
        // 使用指针偏移或数组下标访问
        // (points + i)->setXY(px, py); // 指针偏移方式
        points[i].setXY(px, py);      // 数组下标方式 (更常用)
    }

    // 第一次判断点与圆的关系
    for (int i = 0; i < n; ++i) {
        // 使用指针偏移或数组下标访问
        // if (myCircle.contain(*(points + i)) == 1) { // 指针偏移方式
        if (myCircle.contain(points[i]) == 1) {      // 数组下标方式
            cout << "inside" << endl;
        } else {
            cout << "outside" << endl;
        }
    }

    // 读取新的圆心坐标
    double newX, newY;
    cin >> newX >> newY;
    // 移动圆心
    myCircle.moveCentreTo(newX, newY);
    // 添加移动后的提示输出
    cout << "after move the centre of circle:" << endl;


    // 移动圆心后再次判断点与圆的关系
    for (int i = 0; i < n; ++i) {
        // 使用指针偏移或数组下标访问
        // if (myCircle.contain(*(points + i)) == 1) { // 指针偏移方式
        if (myCircle.contain(points[i]) == 1) {      // 数组下标方式
            cout << "inside" << endl;
        } else {
            cout << "outside" << endl;
        }
    }

    // 释放动态分配的内存
    delete[] points;

    return 0;
}
/*******************************************/
