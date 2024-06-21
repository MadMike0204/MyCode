#include<stdio.h>
int main(void){

    double L,x=0.0;
    double step=2.0;
    scanf("%lf",&L);
    int n=0;
    while(L>0)
    {
        L = L - step;
        step = step * 0.98;
        n++;
    }
    printf("%d",n);

    return 0;
}