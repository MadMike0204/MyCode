#include<iostream>
#include <bitset>
using namespace std;

int main() {
    cout << "please enter two numbers:" << '\n';

    int num1, num2; 
    cin >> num1 >> num2;// num1 乘数  num2 被乘数

    int result = 0;

    for (int i = 32; i; num1 >>= 1, num2 <<= 1, i--) 
    {
        if (num1 & 1) result += num2; // 判断乘数1最低位是否为1，如果为1，加一次num2
    }
    
    cout << "result:" << '\n';
    cout << result << '\n';
    
    return 0;
}