#include <iostream>
#include <iomanip>
using namespace std;
int main(){

    double x = 6.63512;
    cout << setprecision(3) << x << endl
         << fixed << setprecision(9) << x <<endl
         << setprecision(3) << x << endl
         << setw(9) << x << endl
         << x << endl
         << setw(9)
         << setfill('0')<< x << endl;


    return 0;
}