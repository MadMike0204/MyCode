#include<iostream>
#include<iomanip>
using namespace std;
int main(){

    int t;
    double x,y;
    cin >> t;
    while(t--){
        cin >> x >> y;
        cout << fixed << setprecision(1)
             << 0.6 * x + 0.4 * y << endl;
    }

    return 0;
}