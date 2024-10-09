#include <stdio.h>
#include <math.h>
int main(){

    double R,Area;
    int n;
    double pi = 3.1415926;

    scanf("%lf,%d",&R,&n);
    Area = (0.5) * n * R * R * sin(2 * pi / n);
    printf("Area=%.2lf\n",Area);

    return 0;
}