#include <iostream>
#include <vector>
using namespace std;

// 计算最少的与 0 交换次数
int countSwaps(vector<int>& arr, int n) {
    int swaps = 0;
    int zero_pos = 0; // 当前 0 的位置

    // 建立一个位置数组，用于快速查找数字的位置
    vector<int> posMap(n);
    for (int i = 0; i < n; ++i) {
        posMap[arr[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i] != i) {
            // 找到当前 0 的位置
            while (arr[zero_pos] != 0) {
                zero_pos++;
            }

            // 将 0 交换到正确位置
            int target = posMap[i]; // 当前 i 应该在的位置
            swap(arr[zero_pos], arr[target]);

            // 更新位置映射
            posMap[arr[zero_pos]] = zero_pos;
            posMap[arr[target]] = target;

            swaps++;
        }
    }

    return swaps;
}

int main() {
    int n;
    cin >> n; // 读取排列的大小

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // 读取排列
    }

    cout << countSwaps(arr, n) << endl; // 输出最少的交换次数

    return 0;
}
