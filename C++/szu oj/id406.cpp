#include<iostream>
using namespace std;
int main(){
    
    double a[3];
    for(int i=0;i<3;i++){
        cin >> a[i];
    }
    double max = -999;
    for(int i=0;i<3;i++){
        if(max < a[i])
            max = a[i];
    }
    cout << max << endl;

    return 0;
}