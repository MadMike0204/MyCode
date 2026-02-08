#include<iostream>
#include<iomanip>
using namespace std;

#define PI 3.1415926

class Shape{
    public:
    virtual void Circumference() = 0;
};
class Circle: virtual public Shape{
    double r;
    public:
    Circle(double rrr):r(rrr){}
    void Circumference() override{
        cout << "Circumference of Circle: ";
        cout << setprecision(2) << fixed << PI * r * 2.00 << endl;
    }
};
class Square: virtual public Shape{
    double l;
    public:
    Square(double lll):l(lll){}
    void Circumference() override{
        cout << "Circumference of Square: ";
        cout << setprecision(2) << fixed << 4.00 * l << endl;
    }
};
class Rectangle: virtual public Shape{
    double a,b;
    public:
    Rectangle(double aa,double bb):a(aa),b(bb){}
    void Circumference() override{
        cout << "Circumference of Rectangle: ";
        cout << setprecision(2) << fixed << (a + b) * 2.00 << endl;
    }
};

int main(){

    Shape* ptr = nullptr;

    int t;
    cin >> t;
    while(t--){
        double a,b;
        cin >> a;
        ptr = new Circle(a);
        ptr->Circumference();
        if(ptr)
            delete ptr;
        cin >> a;
        ptr = new Square(a);
        ptr->Circumference();
        if(ptr)
            delete ptr;
        cin >> a >> b;
        ptr = new Rectangle(a,b);
        ptr->Circumference();
        if(ptr)
            delete ptr;
    }

    return 0;
}