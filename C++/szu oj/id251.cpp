#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class C2D{
    protected:
        double x,y;
    public:
        C2D(double a,double b):x(a),y(b){}
        double getDistance(){
            return sqrt(x*x+y*y);
        }
};
class C3D:public C2D{
    protected:
        double z;
    public:
        C3D(double a,double b,double c):C2D(a,b),z(c){}
        double getDistance(){
            return sqrt(x*x+y*y+z*z);
        }
};
int main(){

    double a,b,c;
    cin >> a >> b;
    C2D c1(a,b);
    cout << c1.getDistance() << endl;
    cin >> a >> b >> c;
    C3D c2(a,b,c);
    cout << c2.getDistance() << endl;
    cin >> a >> b >> c;
    C3D c3(a,b,c);
    cout << c3.getDistance() << endl;
    C2D* ptr = new C3D(a,b,c);
    cout << ptr->getDistance() << endl;

    return 0;
}