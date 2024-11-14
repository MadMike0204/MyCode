#include<stdio.h>
int main(){

    int n,a,b;
    float i;
    scanf("%d",&n);
    a=2,b=1,i=0;
    while(n--)
    {
        i += (1.0*a/b);
        int t = b;
        b = a;
        a = t+a;
    }

    printf("%.2f",i);
    return 0;
}