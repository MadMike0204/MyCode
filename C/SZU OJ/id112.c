#include<stdio.h>
#include<math.h>
int main(){

    double a,b,c,delta,x1,x2,m,n;
    int s1,s2,s3;
    s1 = isgreater(delta,0.0);
    s2 = isless(delta,0.0);
    scanf("%lf %lf %lf",&a,&b,&c);
    a=1.0*a;
    b=1.0*b;
    c=1.0*c;
    delta = b*b-4*a*c;
    if(isgreater(delta,0.0))
    {
        x1 = (-b*1.0+sqrt(delta))/(2.0*a);
        x2 = (-b*1.0-sqrt(delta))/(2.0*a);
        printf("x1=%.3lf x2=%.3lf",x1,x2);
    }
    else if(isless(delta,0.0))
    {
        m = (-b*1.0)/(2*a);
        n = sqrt(-delta)/(2*a);
        printf("x1=%.3lf+%.3lfi x2=%.3lf-%.3lfi",m,n,m,n);
    }
    else
    {
        x1 = x2 = (-b+sqrt(delta))/(2*a);
        printf("x1=%.3lf x2=%.3lf",x1,x2);
    }
    return 0;
}