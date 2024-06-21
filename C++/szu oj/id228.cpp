#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

static double pi = 3.14;

class CPoint
{   
    protected:
        int x;
        int y;
    public:
        CPoint(int x_in,int y_in):x(x_in),y(y_in){}
        void location()
        {
            cout << "("<<x<<","<<y<<"),";
        }
};
class CCircle:public CPoint
{
    protected:
        int r;
    public:
        CCircle(int x_in,int y_in,int r_in):CPoint(x_in,y_in),r(r_in){}
        double getArea()
        {
            return r*r*pi;
        }
        void getR()
        {
            cout << r << endl;
        }
};
class CCylinder:public CCircle
{
    protected:
        int h;
    public:
        CCylinder(int x_in,int y_in,int r_in,int h_in):CCircle(x_in,y_in,r_in),h(h_in){}
        double getVolume()
        {
            return r*r*pi*h;
        }
        void getRH()
        {
            cout << r << "," << h << endl;
        }
};
int main(){

    int x,y,r,h;
    cin >> x >> y >> r;
    CCircle jojo(x,y,r);
    cout << "Circle:";
    jojo.location();
    jojo.getR();
    cout << fixed << setprecision(2) << "Area:" << jojo.getArea() << endl;
    cin >> x >> y >> r >> h;
    CCylinder newnew(x,y,r,h);
    cout << "Cylinder:";
    newnew.location();
    newnew.getRH();
    cout << fixed << setprecision(2) << "Volume:"<< newnew.getVolume() << endl;
    return 0;
}