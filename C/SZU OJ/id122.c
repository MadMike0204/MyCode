#include<stdio.h>
int main(){

    int n;
    long long x=1;
    scanf("%d",&n);
    int i;
    if(n == 0)
    {
        printf("0!=1");
    }
    else 
    {
        for(i=1;i<=n;i++)
        {
            x = i*x;
        }
    printf("%d!=%lld",n,x);
    }
    return 0;
}