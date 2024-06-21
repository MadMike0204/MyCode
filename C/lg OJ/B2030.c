#include<stdio.h>
#include<math.h>
int main(void)
{
    double a,b,c,d,x,y,D,E;
    scanf("%lf %lf\n%lf %lf",&a,&b,&c,&d);
    x = a-c;
    y = b-d;
    E = sqrt(powf(x,2.0)+powf(y,2.0));
    D = hypotf(x,y);
    printf("%.3lf",E);

    return 0;
}