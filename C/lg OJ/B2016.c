#include<stdio.h>
int main(void){

    double x;
    scanf("%lf",&x);
    long long int m = x;
    printf("%lld",m);

    return 0;
}
//浮点数值在赋值给整型时，小数点部分直接吃掉（向0靠近，正数减小，负数增大）