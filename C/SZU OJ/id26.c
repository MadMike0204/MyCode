#include<math.h>
#include<stdio.h>
int main(void)
{
    double x1,x2,y1,y2;
    double D;
    scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    D = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    printf("%.2lf",D);

    return 0;
}