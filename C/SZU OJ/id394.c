#include<stdio.h>
int main(){

    int a,n,m;
    scanf("%d %d %d",&a,&n,&m);
    double sum;
    sum = a * n + a * 1.0 / 2 * m;
    printf("%.6lf",sum); 


    return 0;
}