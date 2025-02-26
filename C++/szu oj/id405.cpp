#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double F,C;
    cin >> F;
    C = 5.0 / 9.0 * (F-32);
    cout << fixed << setprecision(1) << C << endl;
	return 0;
}