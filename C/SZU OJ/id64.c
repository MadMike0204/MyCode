#include<stdio.h>
int main(){

    int n,k;
    scanf("%d",&n);
    if((n%2)==0)
        printf("%d",n/2);
    else
        printf("%d",(n+1)/2);

    return 0;
}