#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int i, j;  // 定义两个变量，跟踪两个字符串
    int len = strlen(str);  // 获取字符串长度

    for (i = 0, j = len - 1; i < j; i++, j--) {
        // 交换 str[i] 和 str[j]
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {

    char str[100];
    scanf("%s", str);  // 读取字符串 
    reverseString(str);  // 逆序
    printf("逆序后的字符串：%s\n", str);  // 输出逆序字符串

    return 0;
}
