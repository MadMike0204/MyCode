#include<stdio.h>
#include<math.h>
int main(void){

    int a;
    double x,y;
    scanf("%lf %d %lf",&x,&a,&y);
    double REs;
    REs = x + a%3*(int)(x+y)%2/4;
    printf("%.6lf",REs);

    return 0;
}