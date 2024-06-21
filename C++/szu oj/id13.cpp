#include<iostream>
using namespace std;
int main(){

    long W;
    int bonus = 0;
    cin >> W;
    if(W > 1000000)
    {
        bonus += (W-1000000)*0.01;
        bonus += 400000*0.015;
        bonus += 200000*0.03;
        bonus += 200000*0.05;
        bonus += 100000*0.075;
        bonus += 100000*0.1;
    }
    else if(W > 600000)
    {
        bonus += (W-600000)*0.015;
        bonus += 200000*0.03;
        bonus += 200000*0.05;
        bonus += 100000*0.075;
        bonus += 100000*0.1;
    }
    else if(W >400000)
    {
        bonus += (W-400000)*0.03;
        bonus += 200000*0.05;
        bonus += 100000*0.075;
        bonus += 100000*0.1;
    }
    else if(W > 200000)
    {
        bonus += (W-200000)*0.05;
        bonus += 100000*0.075;
        bonus += 100000*0.1;
    }
    else if(W > 100000)
    {
        bonus += (W-100000)*0.075;
        bonus += 100000*0.1;
    }
    else
    {
        bonus += W * 0.1;
    }
    cout << bonus << endl;

    return 0;
}