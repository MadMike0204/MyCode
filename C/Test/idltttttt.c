#include <stdio.h>

int main() {
    int a[6], b[8];
    int i, j;

    // 输入数组1的6个元素
    for (i = 0; i < 6; i++) {
        scanf("%d", &a[i]);
    }

    // 输入数组2的8个元素
    for (i = 0; i < 8; i++) {
        scanf("%d", &b[i]);
    }

    // 查找两个数组的公共元素
    for (i = 0; i < 8; i++) {  // 遍历数组2
        for (j = 0; j < 6; j++) {  // 遍历数组1
            if (b[i] == a[j]) {  // 如果数组2的元素在数组1中存在
                printf("%d\n", b[i]);  // 按数组2的顺序输出
                break;  // 跳出当前循环，避免重复匹配
            }
        }
    }

    return 0;
}
