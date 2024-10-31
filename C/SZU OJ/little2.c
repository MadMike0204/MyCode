#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, x, y, z;
    scanf("%f %f %f", &a, &b, &c);  // 使用单个空格分隔，避免 `\n`

    x = fabs(a - b);
    y = fabs(a - c);
    z = fabs(b - c);

    if (a + b <= c || a + c <= b || b + c <= a)
    {
        printf("非三角形");  // 检查是否满足三角形不等式
    }
    else if (x < 0.001 && y < 0.001)
    {
        printf("等边三角形");  // 检查是否为等边三角形
    }
    else if ((x < 0.001 && fabs(a * a + b * b - c * c) < 0.001) || 
             (y < 0.001 && fabs(a * a + c * c - b * b) < 0.001) || 
             (z < 0.001 && fabs(b * b + c * c - a * a) < 0.001))
    {
        printf("等腰直角三角形");  // 检查是否为等腰直角三角形
    }
    else if (x < 0.001 || y < 0.001 || z < 0.001)
    {
        printf("等腰三角形");  // 检查是否为等腰三角形
    }
    else
    {
        printf("普通三角形");  // 其他情况即为普通三角形
    }
    return 0;
}