#include<stdio.h>
#include<math.h>
int main(void){

    double n;
    scanf("%lf",&n);
    n = fabsf(n);
    printf("%.2lf",n);

    return 0;
}