#include<iostream>
#include<iomanip>
using namespace std;
int main(){

    int n;
    cin >> n;
    
    for(int i=1;i<=9;i++){
        cout << " " << i << "* " << n << "=" 
        << setw(2) << i * n << endl;
    }
    cout << " ";
    return 0;
}