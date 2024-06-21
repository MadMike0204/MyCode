#include<stdio.h>
int main(){

    int a,b,c,sa=0,sb=0;
    double sc=0;
    scanf("%d %d %d",&a,&b,&c);
    int i;
    for(i=1;i<=a;i++)
    {
        sa += i;
    }
    for(i=1;i<=b;i++)
    {
        sb += i*i;
    }
    for(i=1;i<=c;i++)
    {
        sc += 1.0/i;
    }
    printf("%.2lf",sa+sb+sc);

    return 0;  
}