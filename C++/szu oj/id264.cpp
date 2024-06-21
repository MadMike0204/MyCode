#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
static double PI = 3.14;

class Geometry
{
    public:
        virtual double getArea()=0;//计算面积
};
class Rect:public Geometry
{
    private:
        double length,width;
    public:
        Rect(double l,double w):length(l),width(w){}
        virtual double getArea()
        {
            return length * width;
        }
};
class Circle:public Geometry
{
    private:
        double radiu;
    public:
        Circle(double r):radiu(r){};
        virtual double getArea()
        {
            return radiu * radiu * PI;
        }
};
class TotalArea
{
    public:
        static void computerMaxArea(Geometry** pp,int n)
        {
            double cur;
            double max = -9999;
            for(int i=0;i<n;i++)
            {
                cur = pp[i]->getArea();
                if(cur > max)
                    max = cur;
            }
            cout << "最大面积=" << fixed << setprecision(2) << max;
        }
};

int main(){

    Geometry** pp = NULL;
    Circle* C;
    Rect* R;
    
    int t,type;
    double l,w,r;
    cin >> t;
    int n = t;
    pp = new Geometry*[t];
    while(t > 0)
    {
        t--;

        cin >> type;
        if(type == 1)
        {   
            cin >> l >> w;
            R = new Rect(l,w);
            pp[t] = R;
        }   
        else
        {
            cin >> r;
            C = new Circle(r);
            pp[t] = C;
        }
    }
    TotalArea A;
    A.computerMaxArea(pp,n);

    return 0;
}