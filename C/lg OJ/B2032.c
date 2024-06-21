#include<stdio.h>
int main(void){

    int a1,a2,d,n,an;
    scanf("%d %d %d",&a1,&a2,&n);
    d = a2-a1;
    an = a1 + d*(n-1);
    printf("%d",an);

    return 0;
}