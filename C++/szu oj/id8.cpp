#include <iostream>
#include <cmath>
using namespace std;
int main(){

    int t,num,bits;
    bool is_end_have6,is_6_times_bits,is_6_times;
    cin >> t;
    while(t>0)
    {
        bits = 9;
        is_6_times = 0;
        is_end_have6 = 0;
        is_6_times_bits = 0;
        cin >> num;
        int i;
        for(i=8;i>0;i--)
        {
            if(num % (int)pow(10,i) == num)
            {
                bits--;
            }
        }
        if(num%6 == 0)
            is_6_times = 1;
        if(bits%6 == 0)
            is_6_times_bits = 1;
        if(num%10 == 6)
            is_end_have6 = 1;
        if(is_6_times || is_6_times_bits || is_end_have6)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
        t--;
    }

    return 0;
}