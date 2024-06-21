#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point
{
    double x,y;
    public:
        Point();
        Point(double x_value,double y_value);
        double getX();
        double getY();
        void setXY(double x1,double y1);
        void setX(double x_value);
        void setY(double y_value);
        double getDisTo(Point &p);
        ~Point()
        {
            cout << "Distructor." << endl;
        }
};

Point::Point()
{
    x = 0;
    y = 0;
    cout << "Constructor." << endl;
}
Point::Point(double x_value,double y_value)
{
    x = x_value;
    y = y_value;
    cout << "Constructor." << endl;
}
double Point::getX()
{
    return x;
}
double Point::getY()
{
    return y;
}
void Point::setX(double x_value)
{
    x = x_value;
}
void Point::setY(double y_value)
{
    y = y_value;
}
void Point::setXY(double x1,double y1)
{
    x = x1;
    y = y1;
}
double Point::getDisTo(Point &p)
{
    double distance = sqrt((p.getX()-x)*(p.getX()-x)+(p.getY()-y)*(p.getY()-y));
    return distance;
}

int main(){

    int t;
    cin >> t;
    while(t > 0)
    {
        int number;
        cin >> number;
        Point points[number];
        for(int i=0;i<number;i++)
        {
            int x,y;
            cin >> x >> y;
            points[i].setXY(x,y);
        }
        double distance = -9999,temp;
        int p_1,p_2;
        for(int i=0;i<number-1;i++)
        {
            int k=i;
            for(int j=k+1;j<number;j++)
            {
                temp = points[i].getDisTo(points[j]);
                if(temp > distance)
                {
                    distance = temp;
                    p_1 = i;
                    p_2 = j;
                }
            }
        }
        cout << fixed << setprecision(2) << "The longeset distance is " << distance;
        cout << ",between p[" << p_1 << "]" << " and p[" << p_2 << "]." << endl;
        t--;
    }

    return 0;
}