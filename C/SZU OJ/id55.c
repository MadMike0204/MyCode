#include <stdio.h>
#include <math.h>
int main(){

    float R,Area;
    int n;
    float pi = 3.1415926;

    scanf("%f,%d",&R,&n);
    Area = n * R * R * sin(2 * pi / n)/2;
    printf("Area=%.2f\n",Area);

    return 0;
}