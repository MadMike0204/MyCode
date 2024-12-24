#include <iostream>
#include <vector>
using namespace std;

// 计算冒泡排序所需交换次数的函数
int bubbleSortSwaps(vector<int>& arr) {
    int n = arr.size();
    int swapCount = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ++swapCount;
            }
        }
    }
    return swapCount;
}

int main() {
    int n;
    // 标准输入多组测试数据
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        // 调用冒泡排序交换次数函数
        cout << bubbleSortSwaps(arr) << endl;
    }

    return 0;
}
