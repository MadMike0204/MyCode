#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    
    // 处理多组测试数据
    while (cin >> n) {
        // 使用set自动排序并去重
        set<int> unique_elements;
        
        // 读取n个整数
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            unique_elements.insert(num);
        }
        
        // 遍历set中的元素(已经是有序的了)
        bool first = true;
        for (int elem : unique_elements) {
            if (first) {
                cout << elem;
                first = false;
            } else {
                cout << " " << elem;
            }
        }
        cout << endl;
    }
    
    return 0;
}
