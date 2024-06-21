#include<stdio.h>
int main(){

    int a,b,k;
    scanf("%d %d",&a,&b);
    k = a*a+b*b;
    if(k>100)
        printf("%d",k/100);
    else 
        printf("%d",k);

    return 0;
}