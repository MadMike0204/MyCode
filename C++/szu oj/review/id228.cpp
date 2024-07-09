#include <iostream>
#include <iomanip>
using namespace std;

static double PI = 3.14;

class CPoint
{
    protected:
        int x,y;
    public:
        CPoint(int a=0,int b=0):x(a),y(b){}
        void PrintP()
        {
            cout << "(" << x << "," << y << ")";
        }
};
class CCircle:public CPoint
{
    protected:    
        int r;
    public:
        CCircle(int a=0,int b=0,int c=0):CPoint(a,b),r(c){}
        double GetArea()
        {
            return PI * r * r;
        }
        void PrintC()
        {
            cout << "Circle:";
            PrintP();
            cout << "," << r << endl
                 << "Area:" << fixed << setprecision(2) << GetArea() << endl;
        }
};
class CCylinder:public CCircle
{
    private:
        int h;
    public:
        CCylinder(int a=0,int b=0,int c=0,int d=0):CCircle(a,b,c),h(d){}
        double GetV()
        {
            return GetArea() * h;
        }
        void PrintCy()
        {
            cout << "Cylinder:";
            PrintP();
            cout << "," << r << "," << h << endl
                 << "Volume:" << fixed << setprecision(2) << GetV() << endl;
        }
};

int main(){

    int a,b,c,d;
    cin >> a >> b >> c;
    CCircle j(a,b,c);
    j.PrintC();
    cin >> a >> b >> c >> d;
    CCylinder o(a,b,c,d);
    o.PrintCy();

    return 0;
}