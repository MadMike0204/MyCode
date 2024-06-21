#include <iostream>
#include <iomanip>
using namespace std;
int main(){

    int t;
    cin >> t;
    double USD = 6.2619,EUR = 6.6744,JPY = 0.0516,HKD = 0.8065;
    const double* p = &USD;
    char BB;
    double num;
    while(t>0)
    {
        cin >> BB;
        cin >> num;
        switch(BB)
        {
            case 'Y':
                p = &JPY;
                num = num * *p;
                break;
            case 'D':
                p = &USD;
                num = num * *p;
                break;
            case 'H':
                p = &HKD;
                num = num * *p;
                break;
            case 'E':
                p = &EUR;
                num = num * *p;
        }
        cout << fixed << setprecision(4) << num << endl;
        t--;
    }

    return 0;
}