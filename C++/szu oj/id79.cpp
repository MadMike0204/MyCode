#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Point
{
    double x,y;
    public:
        double getX();
        double getY();
        Point(double x_value,double y_value);
        Point();
        void setX(double x_value);
        void setY(double y_value);
        double distanceToAnotherPoint(Point p);

};

double Point::getX()
{
    return x;
}
double Point::getY()
{
    return y;
}
Point::Point()
{   
    x = 0;
    y = 0;
    return;
}
Point::Point(double x_value,double y_value)
{
    x = x_value;
    y = y_value;
    return;
}
void Point::setX(double x_value)
{
    x = x_value;
    return;
}
void Point::setY(double y_value)
{
    y = y_value;
    return;
}
double Point::distanceToAnotherPoint(Point p)
{
    double distance;
    distance = sqrt((x-p.getX())*(x-p.getX()) + ((y-p.getY()))*(y-p.getY()));
    return distance;
}

int main(){

    int t;
    cin >> t;
    while(t>0)
    {
        double x,y;

        cin >> x >> y;
        Point p1(x,y);
        cin >> x >> y;
        Point p2(x,y);

        double dist = p1.distanceToAnotherPoint(p2);
        cout << fixed << setprecision(2) << "Distance of Point(" 
             << p1.getX() << "," << p1.getY() << ") to Point(" 
             << p2.getX() << "," << p2.getY() << ") is " << dist << endl; 
        t--;
    }


    return 0;
}