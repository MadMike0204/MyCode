#include<stdio.h>
int main(){

    int arr[10],sum=0,count=0;
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<10;i++)
    {
        sum += arr[i];
    }
    for(i=0;i<10;i++)
    {
        if(arr[i]>1.0*sum/10)
            count++;
    }
    printf("%d",count);
    return 0;
}