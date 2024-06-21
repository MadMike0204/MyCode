#include<stdio.h>
int main(void){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    long long s;
    s = (a+b)/c;
    printf("%lld",s);
    return 0;
}