#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape {
protected:
    string name;
    double x, y;
public:
    Shape(double x = 0, double y = 0) : x(x), y(y) {}
    virtual ~Shape() {}

    virtual string getName() const { return name; }
    virtual double getX() const { return x; }
    virtual double getY() const { return y; }
    virtual double getArea() const { return 0.0; }
    virtual double getVolume() const { return 0.0; }

    virtual void shapeName() = 0;
};

class Point : public Shape {
public:
    Point(double x = 0, double y = 0) : Shape(x, y) {
        shapeName();
    }
    
    virtual void shapeName() {
        name = "Point";
    }
};

class Circle : public Point {
protected:
    double r; 
public:
    Circle(double x = 0, double y = 0, double radius = 0) : Point(x, y), r(radius) {
        shapeName();
    }
    
    virtual void shapeName() {
        name = "Circle";
    }
    
    virtual double getArea() const {
        const double PI = 3.14159;
        return PI * r * r;
    }
};

class Cylinder : public Circle {
private:
    double h; 
public:
    Cylinder(double x = 0, double y = 0, double radius = 0, double height = 0) 
        : Circle(x, y, radius), h(height) {
        shapeName();
    }
    virtual void shapeName() {
        name = "Cylinder";
    }
    virtual double getArea() const {
        const double PI = 3.14159;
        return 2 * PI * r * r + 2 * PI * r * h; 
    }
    

    virtual double getVolume() const {
        const double PI = 3.14159;
        return PI * r * r * h;
    }
};

void Print(Shape* shape) {
    cout << shape->getName() << "--(" << shape->getX() << "," << shape->getY() << ")--"
         << (int)shape->getArea() << "--" << (int)shape->getVolume() << endl;
}

int main() {
    double x1, y1;
    double x2, y2, r2;
    double x3, y3, r3, h3;
    
    cin >> x1 >> y1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3 >> h3;
    
    Shape* p1 = new Point(x1, y1);
    Shape* p2 = new Circle(x2, y2, r2);
    Shape* p3 = new Cylinder(x3, y3, r3, h3);
    
    Print(p1);
    Print(p2);
    Print(p3);
    
    delete p1;
    delete p2;
    delete p3;
    
    return 0;
}
