#include<stdio.h>
int main(void){

    const double pi = 3.14159;
    double r,d,c,s;
    scanf("%lf",&r);
    d = 2*r;
    c = d*pi;
    s = pi*r*r;
    printf("%.4lf %.4lf %.4lf",d,c,s);

    return 0;
}