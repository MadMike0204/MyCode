#include <iostream>
using namespace std;

int main() {
    double num1;
    int num2;
    
    cout << "Enter a floating-point number: ";
    cin >> num1;
    cin.ignore(); // 清除输入缓冲区中的换行符
    cout << "Enter an integer: ";
    cin >> num2;
    
    cout << "You entered: " << num1 << " and " << num2 << endl;
    
    return 0;
}