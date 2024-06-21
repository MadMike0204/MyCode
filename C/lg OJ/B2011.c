#include<stdio.h>
int main(void){

    long long a,b=5;
    scanf("%lld %lld",&a,&b);
    double c;
    c = (1.0*a)/(1.0*b)*1.0;
    printf("%.9f",c); 

    return 0;
}
//如果希望得到浮点数的结果，两个运算数必须至少有一个浮点数，这时 C 语言就会进行浮点数除法。