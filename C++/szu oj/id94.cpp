#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Equation
{
    private:
        double a;
        double b;
        double c;
        double delta;
    public:
        Equation()
        {
            a = 1;
            b = 1;
            c = 0;
            delta = 1;
        }
        Equation(double x,double y,double z)
        {
            a = x;
            b = y;
            c = z;
            delta = b * b - 4 * a * c;
        }
        void setE(double x,double y,double z)
        {
            a = x;
            b = y;
            c = z;
            delta = b * b - 4 * a * c;
        }
        void getroot()
        {
            double root1 = -999,root2 = -999;
            if(delta > 0)
            {
                root1 = (-b+sqrt(delta))/(2*a*1.0);
                root2 = (-b-sqrt(delta))/(2*a*1.0);
                cout << fixed << setprecision(2) << "x1=" << root1 << " x2=" << root2 << endl;
            }
            else if(fabs(delta) < 0.001)
            {
                root1 = root2 = -b/(a*2.0);
                cout << fixed << setprecision(2) << "x1=x2=" << root1 << endl;
            }
            else if(delta < 0)
            {
                cout << fixed << setprecision(2) << showpos 
                << "x1=" << -b/(2*a) << sqrt(-delta)/(2*a) << "i " 
                << "x2=" << -b/(2*a) << -sqrt(-delta)/(2*a) << "i" << endl;
            }
        }
};

int main(){

    int t;
    cin >> t;
    while(t > 0)
    {
        Equation jostar_equation;
        double a,b,c;
        cin >> a >> b >> c;
        jostar_equation.setE(a,b,c);
        jostar_equation.getroot();
        t--;
    }

    return 0;
}