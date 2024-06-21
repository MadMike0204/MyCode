#include<stdio.h>
int main(){

    char str[44];
    int len;
    scanf("%d",&len);
    getchar();
    scanf("%s",str);
    int i;
    for(i=len-1;i>=0;i--)
    {
        printf("%c",str[i]);
    }

    return 0;
}