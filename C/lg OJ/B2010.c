#include<stdio.h>
int main(void){

    int a,b,c,d;
    scanf("%d %d",&a,&b);
    c = a%b;
    d = (a-c)/b;
    printf("%d %d",d,c);

    return 0;
}