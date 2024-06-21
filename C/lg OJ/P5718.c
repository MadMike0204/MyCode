#include<stdio.h>
int main(void){

    int n;
    scanf("%d",&n);
    int i;
    int num[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    int temp = num[0];
    for(i=0;i<n;i++)
    {
        if(num[i]<temp) temp = num[i];
    }
    printf("%d",temp);

    return 0;
}