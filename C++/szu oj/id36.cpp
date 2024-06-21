#include <iostream>
#include <cmath>
using namespace std;

double Sqrt(double x);
int Sqr(int x);
void Captical(char* str);


int main(){

    int t,a;
    double b;
    char str[999],Vaule;
    cin >> t;
    while(t > 0)
    {
        cin >> Vaule;
        if(Vaule == 'S')
        {
            cin >> str;
            void (*func) (char* str) = Captical;
            (*func)(str);
            cout << str << endl;
        }
        else if(Vaule == 'F')
        {
            cin >> b;
            double (*func) (double x) = Sqrt;
            cout << (*func) (b) << endl;
        }
        else if(Vaule == 'I')
        {
            cin >> a;
            int (*func) (int x) = Sqr;
            cout << (*func) (a) << endl;
        }
        t--;
    }
    return 0;
}

double Sqrt(double x)
{
    return sqrt(x);
}
int Sqr(int x)
{
    return (x*x);
}
void Captical(char* str)
{
    for(int i=0;;i++)
    {
        if(*(str+i) == 0)
        {
            break;
        }
        if(*(str+i) >= 'a' && *(str+i) <= 'z')
        {
            *(str+i) -= 32;
        }
    }
}