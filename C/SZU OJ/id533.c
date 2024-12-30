#include <stdio.h>
// 函数声明
void sort(int a[], int n);           // 升序排序 冒泡
int find(int a[], int n, int value); // 查找函数
void display(int a[], int n);        // 输出函数
void reverse(int a[], int n);        // 逆序 (升序<>降序)

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int arr[11];
        int n = 10;   // 初始长度为10
        // 输入10个整数
        for (int i = 0; i < 10; i++) {
            scanf("%d", &arr[i]);
        }

        int a;
        scanf("%d", &a); // 输入a

        // 1：a为奇数，在数组中
        if (a % 2 != 0 && find(arr, n, a) != -1) {
            int index = find(arr, n, a); // 找到a的下标
            // 删除方法：将这个数后面的数前移1位，覆盖掉这个数
            for (int i = index; i < n - 1; i++) {
                arr[i] = arr[i + 1]; // 删除a
            }
            n--;               // 长度减1
            sort(arr, n);
            display(arr, n);

        // 2：a为偶数，不在数组中
        } else if (a % 2 == 0 && find(arr, n, a) == -1) {
            arr[n++] = a;      // 将a加入数组
            sort(arr, n);      // 先升序排序
            reverse(arr, n);   // 再逆序排列
            display(arr, n);   // 输出结果

        // 3：其他情况
        } else {
            int odd[10], even[10]; // 分别存放奇数和偶数
            int oddCount = 0, evenCount = 0;

            // 分离奇数和偶数
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 != 0) {
                    odd[oddCount++] = arr[i];
                } else {
                    even[evenCount++] = arr[i];
                }
            }
            // 分别排序
            sort(odd, oddCount);
            sort(even, evenCount);
            // 逆序排列
            reverse(odd, oddCount);
            reverse(even, evenCount);

            // 合并结果
            for (int i = 0; i < oddCount; i++) {
                arr[i] = odd[i];
            }
            for (int i = 0; i < evenCount; i++) {
                arr[oddCount + i] = even[i];
            }

            display(arr, n); // 输出结果
        }
    }

    return 0;
}

// 升序排序--冒泡排序
void sort(int a[],int n)
{
    int flag = 1;
    int temp;
    while(flag)
    {
        flag = 0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i] > a[i+1])//升序
            {
                flag = 1;
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
}

// 查找函数
int find(int a[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            return i; // 返回找到的下标
        }
    }
    return -1; // 找不到返回-1
}

// 输出
void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

// 数组反转函数
void reverse(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}