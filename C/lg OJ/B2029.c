#include<stdio.h>
int main(void){

    double const pi = 3.14;
    double const mL = 20000;
    int h,r;
    scanf("%d %d/n",&h,&r);
    int S = 0;
    double V = 0;
    while(1)
    {
        V = V+pi*r*r*h;
        S++;
        if(V>=mL)
        {
            printf("%d",S);
            break;
        }
    }
    return 0;
}