#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i, j, len;
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < len; i++) {
        if (str[i] != str[i + 1]) {
            printf("%c", str[i]);
        }
    }

    return 0;
}