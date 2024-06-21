#include<stdio.h>
int main(){

    int arr[101];
    int i;
    for(i=1;i<=101;i++)
    {
        arr[i] = 3*i-1;
    }
    int sum=0,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum += arr[i];
    }
    printf("%d",sum);
    
    return 0;
}