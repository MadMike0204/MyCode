#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

class CTriangle{
    public:
        string type;
        double a,b,c;
    public:
        CTriangle(double ina,double inb,double inc):a(ina),b(inb),c(inc)
        {   
            double arr[3] = {a,b,c};
            sort(arr,arr+3);
            if(arr[0]+arr[1] < arr[2])
            {
                type = "no triangle";
            }
            else if((arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2]) && arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
            {
                type = "isosceles right triangle";
            }
            else if(arr[0] == arr[1] && arr[1] != arr[2] && arr[0]*arr[0] + arr[1] * arr[1] != arr[2] * arr[2])
            {
                type = "isosceles triangle";
            }
            else if(arr[0] == arr[1] && arr[1] == arr[2])
            {
                type = "equilateral triangle";
            }
            else if(arr[0]*arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
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
            double p = (a+b+c)/2;
            double S = sqrt(p*(p-a)*(p-b)*(p-c));
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
