#include<stdio.h>
#include<string.h>
int main(){

    char num[5];
    memset(num,0,sizeof(num));
    scanf("%s",&num);
    int i = 0;
    while(i<=5)
    {
        if(num[i] != 0)
            i++;
        else
            break;
    }
    int n = i;
    printf("%d\n",n);
    for(i=0;i<n-1;i++)
    {
        printf("%c ",num[i]);
    }
    printf("%c\n",num[n-1]);
    for(i=n-1;i>=0;i--)
    {
        printf("%c",num[i]);
    }

    return 0;
}