#include<stdio.h>
int main(void){

    double R1,R2,R;
    scanf("%lf %lf",&R1,&R2);
    R = 1/(1/R1+1/R2);
    printf("%.2lf",R);
    
    return 0;
}