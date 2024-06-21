#include<stdio.h>
int main(){

    int r,q,n;
    int a[6] = {100,50,20,10,5,1};
    scanf("%d",&n);
    int i;
    for(i=0;i<6;i++)
    {
        q = n/a[i];
        n = n%a[i];
        printf("%d ",q);
    }


    return 0;
}