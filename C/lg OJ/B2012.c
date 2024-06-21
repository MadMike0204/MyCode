#include<stdio.h>
int main(void){

    int a,b;
    scanf("%d\n%d",&a,&b);
    double c;
    c = ((b*1.0)/(a*1.0))*100;
    printf("%.3f%%",c);

    return 0;
}
//