#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point
{
    protected:
        double x;
    public:
        Point(double x_in)
        {
            x = x_in;
        }
        double Distance()
        {
            return fabs(x);
        }
};
Point::Point(double x_in)
{
    
}
class Point_2D: public Point
{   
    protected:
        double y;
    public:
        Point_2D(double x_in,double y_in):Point(x_in),y(y_in){}
        double Distance()
        {
            return sqrt(x*x+y*y);
        }
};
class Point_3D: public Point_2D
{
    protected:
        double z;
    public:
        Point_3D(double x_in,double y_in,double z_in):Point_2D(x_in,y_in),z(z_in){}
        double Distance()
        {
            return sqrt(x*x+y*y+z*z);
        }
};

int main(){

    while(1)
    {
        int dim;
        double x,y,z;
        cin >> dim;
        if(dim == 0)
        {
            break;
        }
        else if(dim == 1)
        {
            cin >> x;
            Point jojo(x);
            cout << "Distance between [" << x << "] and [0] = ";
            cout << fixed << setprecision(2) << jojo.Distance() << endl;
        }
        else if(dim == 2)
        {
            cin >> x >> y;
            Point_2D jojo(x,y);
            cout << "Distance between [" << x << ", " << y << "] and [0, 0] = ";
            cout << fixed << setprecision(2) << jojo.Distance() << endl;
        }
        else if(dim == 3)
        {
            cin >> x >> y >> z;
            Point_3D jojo(x,y,z);
            cout << "Distance between [" << x << ", " << y << ", " << z << "] and [0, 0, 0] = ";
            cout << fixed << setprecision(2) << jojo.Distance() << endl;
        }
    }

    return 0;
}