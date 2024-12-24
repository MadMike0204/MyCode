#include <iostream>
#include <vector>
using namespace std;

// 希尔排序的实现函数
void shellSort(vector<int>& arr) {
    int n = arr.size();
    // 初始间隔gap为n/2，逐步减小到1
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 从gap开始，对各组进行插入排序
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        // 输出当前趟排序的结果
        for (int k = 0; k < n; ++k) {
            if (k > 0) cout << " ";
            cout << arr[k];
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t; // 读取测试示例数量

    for (int test = 0; test < t; ++test) {
        if (test > 0) cout << endl; // 不同测试数据间空行分隔

        int n;
        cin >> n; // 读取当前测试示例的数据数量

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i]; // 读取数据
        }

        shellSort(arr); // 调用希尔排序函数
    }

    return 0;
}
