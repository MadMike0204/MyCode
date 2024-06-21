#include<stdio.h>
int main(void){
    
    double F;
    scanf("%lf",&F);
    double C;
    C = 5*(F-32)/9;
    printf("%.5lf",C);

    return 0;
}
/*
%f：float类型浮点数。
%lf：double类型浮点数。
%Lf：long double类型浮点数。
*/