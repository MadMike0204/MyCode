#include<stdio.h>
int main(){

    double m;
    int a,b;
    scanf("%d %d",&a,&b);
    m = 100.0*b/a;
    printf("%.3lf%%",m);

    return 0;
}