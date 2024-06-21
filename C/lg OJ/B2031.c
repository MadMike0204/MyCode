#include<stdio.h>
#include<math.h>
int main(void){

    double x1,x2,x3,y1,y2,y3;
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
    double L1,L2,L3,S,p;
    L1 = sqrtf(powf(x1-x2,2)+powf(y1-y2,2));
    L2 = sqrtf(powf(x2-x3,2)+powf(y2-y3,2));
    L3 = sqrtf(powf(x3-x1,2)+powf(y3-y1,2));
    p = (L1+L2+L3)/2;
    S = sqrtf(p*(p-L1)*(p-L2)*(p-L3));
    printf("%.2lf",S);
    
    return 0;
}