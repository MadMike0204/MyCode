#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

static const double epsilon = 1e-3;  // 容差值

class CTriangle{
    public:
        string type;
        double a,b,c;

    public:
        CTriangle(double ina,double inb,double inc):a(ina),b(inb),c(inc)
        {   
            double arr[3] = {a,b,c};
            sort(arr,arr+3);
            double s = arr[0] * arr[0] + arr[1] * arr[1] - arr[2] * arr[2];
            // 比较浮动点数时用容差值
            if(arr[0] + arr[1] < arr[2] - epsilon)
            {
                type = "no triangle";
            }
            else if((fabs(arr[0] - arr[1]) < epsilon || fabs(arr[0] - arr[2]) < epsilon || fabs(arr[1] - arr[2]) < epsilon) 
                    && fabs(arr[0] * arr[0] + arr[1] * arr[1] - arr[2] * arr[2]) < epsilon)
            {
                type = "isosceles right triangle";
            }
            else if(fabs(arr[0] - arr[1]) < epsilon && fabs(arr[1] - arr[2]) > epsilon 
                    && fabs(arr[0] * arr[0] + arr[1] * arr[1] - arr[2] * arr[2]) > epsilon)
            {
                type = "isosceles triangle";
            }
            else if(fabs(arr[0] - arr[1]) < epsilon && fabs(arr[1] - arr[2]) < epsilon)
            {
                type = "equilateral triangle";
            }
            else if(fabs(arr[0] * arr[0] + arr[1] * arr[1] - arr[2] * arr[2]) < epsilon)
            {
                type = "right triangle";
            }
            else 
            {
                type = "general triangle";
            }
            cout << type;
        }
        ~CTriangle()
        {
            a = 0;
            b = 0;
            c = 0;
            type = "none";
        }
        double SSS()
        {
            double p = (a + b + c) / 2;
            double S = sqrt(p * (p - a) * (p - b) * (p - c));
            return S;
        }

};

int  main()
{
    int t;
    cin >> t;
    double a,b,c;
    while(t--)
    {   
        cin >> a >> b >> c;
        CTriangle tri(a,b,c);
        if(tri.type != "no triangle")
        {
            cout << ", " << fixed << setprecision(1) << tri.SSS();
        }
        cout << endl;
    }
    return 0;
}
