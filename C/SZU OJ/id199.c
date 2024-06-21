#include<stdio.h>
#include<string.h>
int main(){

    int a,n;
    long times,x = 1;
    long sum = 0;
    scanf("%d %d",&a,&n);
    int num[n];
    memset(num,0,sizeof(num));
    int i,j;
    for(j=0;j<n;j++)
    {
        times = 1;
        for(i=0;i<=j;i++)
        {
            x = a*times;
            num[j] += x;
            times = times * 10;
        }
        sum += num[j];
    }
    printf("%d",sum);

    return 0;
}