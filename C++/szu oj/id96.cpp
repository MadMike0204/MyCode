#include <iostream>
#include <iomanip>
#include <cmath>

static const double precision = 0.0001;
static const double PI = 3.14159;

using namespace std;

class Point
{   private:
        double x,y;
    public:
        double getX()
        {
            return x;
        }
        double getY()
        {
            return y;
        }
        Point();
        Point(double x_value,double y_value);

        void setXY(double x_value,double y_value)
        {
            x = x_value;
            y = y_value;
            return;
        }
        ~Point()
        {
            x = 0;
            y = 0;
            cout << "point clear" << endl;
        }
        
};

class Circle
{
    private:
        double x,y,r;
    public:
        Circle(double x_value,double y_value,double r_value)
        {
            x = x_value;
            y = y_value;
            r = r_value;
            return;
        }
        int Contain(int x_value,int y_value)
        {
            double distance;
            distance = sqrt((x-x_value)*(x-x_value) + ((y-y_value))*(y-y_value));
            if(fabs(distance-r) < precision)
            {
                return 0;
            }
            else if(fabs(distance-r) > precision && distance-r > 0)
            {
                return 1;//在圆外，返回正数
            }
            else if(fabs(distance-r) > precision && distance-r < 0)
            {
                return 0;//在圆内，返回0
            }
            return -1;
        }
        double getArea()
        {
            return r*r*PI;
        }
        ~Circle()
        {
            x = 0;
            y = 0;
            cout << "circle clear" << endl;
        }
};
Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double x_value,double y_value)
{
    x = x_value;
    y = y_value;
    return;
}

int main(){

    double x,y;
    cin >> x >> y;
    Point A(x,y);
    int n;
    cin >> n;
    Point* points = new Point[n];


//初始化
    int r;
    cin >> x >> y >> r;
    Circle CC(x,y,r);

    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        (points+i)->setXY(x,y);
    }

    if(CC.Contain(A.getX(),A.getY()) == 1)
        {
            cout << "outside" << endl;
        }
        else if(CC.Contain(A.getX(),A.getY()) == 0)
        {
            cout << "inside" << endl;
        }
    for(int i=0;i<n;i++)
    {
        if(CC.Contain((points+i)->getX(),(points+i)->getY()) == 1)
        {
            cout << "outside" << endl;
        }
        else if(CC.Contain((points+i)->getX(),(points+i)->getY()) == 0)
        {
            cout << "inside" << endl;
        }
    }

    


    return 0;
}