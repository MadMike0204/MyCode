#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 字符串转换为double型实数的函数
double strToDouble(char str[]) {

    double result = 0.0; // 最终结果
    double fractionPart = 0.0; // 小数部分
    int sign = 1; // 符号标志，默认为正数
    int isFraction = 0; // 是否进入小数点部分
    double divisor = 10.0; // 小数部分的除数

    // 处理正负号
    if (str[0] == '-') {
        sign = -1; // 负数
    } else if (str[0] == '+') {
        sign = 1; // 正数，符号保持为1
    }

    // 遍历字符串
    for (int i = 0; str[i] != '\0'; i++) {
        // 处理数字部分
        if (isdigit(str[i])) {
            if (isFraction) {
                // 如果是小数部分，累加到小数部分
                fractionPart += (str[i] - '0') / divisor;
                divisor *= 10.0;
            } else {
                // 如果是整数部分，累加到结果
                result = result * 10 + (str[i] - '0');
            }
        }
        // 处理小数点
        else if (str[i] == '.') {
            isFraction = 1; // 标记进入小数部分
        }
    }

    // 返回结果，考虑符号和小数部分
    return sign * (result + fractionPart);
}

int main() {
    int t; // 测试实例个数

    scanf("%d", &t);
    getchar();

    char str[11]; // 存储字符串，最多10个字符

    for (int i = 0; i < t; i++) {

        fgets(str, sizeof(str), stdin);
        // 去除换行符
        str[strcspn(str, "\n")] = '\0';

        // 调用函数并输出结果，保留6位有效数字
        printf("%.6g\n", strToDouble(str));
    }

    return 0;
}
