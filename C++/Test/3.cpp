#include <iostream>
#include <string>

using namespace std;
int main(){

    int arr[6] = {10,20,30,40,50,60};
    double x = 9.231;
    double* p = &x;
    int m = (int) x;
    cout << (int) x << endl 
         << m << endl   
         << x << endl;


    

    return 0;
}