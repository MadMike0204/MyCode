#include <iostream>
#include <string>
using namespace std;

class CXGraph {
private:
    int n; // X图案的行数

public:
    // 构造函数，初始化行数
    CXGraph(int n) {
        this->n = n;
    }

    // 重载输出运算符，显示X图案
    friend ostream& operator<<(ostream& os, const CXGraph& xg) {
        int mid = (xg.n + 1) / 2; // 中间行位置
        
        for (int i = 1; i <= xg.n; i++) {
            int spaces, x_count;
            
            if (i <= mid) {
                spaces = i - 1;
            } else {
                spaces = xg.n - i;
            }
            
            x_count = xg.n - 2 * spaces;
            
            // 输出空格
            for (int j = 0; j < spaces; j++) {
                os << " ";
            }
            
            // 输出X
            for (int j = 0; j < x_count; j++) {
                os << "X";
            }
            
            os << endl;
        }
        return os;
    }

    // 前缀++运算符，先放大再返回
    CXGraph& operator++() {
        if (n < 21) {
            n += 2;
        }
        return *this;
    }

    // 后缀++运算符，先返回再放大
    CXGraph operator++(int) {
        CXGraph temp = *this;
        if (n < 21) {
            n += 2;
        }
        return temp;
    }

    // 前缀--运算符，先缩小再返回
    CXGraph& operator--() {
        if (n > 1) {
            n -= 2;
        }
        return *this;
    }

    // 后缀--运算符，先返回再缩小
    CXGraph operator--(int) {
        CXGraph temp = *this;
        if (n > 1) {
            n -= 2;
        }
        return temp;
    }
};

int main() {
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--) {
        cin >> command;
        if (command == "show++")
            cout << xGraph++ << endl;
        else if (command == "++show")
            cout << ++xGraph << endl;
        else if (command == "show--")
            cout << xGraph-- << endl;
        else if (command == "--show")
            cout << --xGraph << endl;
        else if (command == "show")
            cout << xGraph << endl;
    }
    return 0;
}
