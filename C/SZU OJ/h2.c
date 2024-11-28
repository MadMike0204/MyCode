#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar(); // 清除换行符
    while (n--)
    {
        int k, b;
        scanf("%d %d", &k, &b);
        getchar(); // 清除换行符

        char c[500];
        fgets(c, sizeof(c), stdin); // 使用更安全的 fgets 替代 gets
        int i;

        for (i = 0; c[i] != '\0'; i++)
        {
            int y;
            if (c[i] >= 'a' && c[i] <= 'z') // 小写字母
            {
                int x = c[i] - 'a';
                y = (k * x + b) % 26;
                c[i] = y + 'a';
            }
            else if (c[i] >= 'A' && c[i] <= 'Z') // 大写字母
            {
                int x = c[i] - 'A';
                y = (k * x + b) % 26;
                c[i] = y + 'A';
            }
            // 对于非字母字符，不做任何处理
        }

        printf("%s\n", c);
    }
    return 0;
}
