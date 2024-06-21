#include<stdio.h>
int main(void){

    int m,n,S;
    m = S = 0;
    scanf("%d",&n);;
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&m);
        S = S+m;
    }
    double s;
    s = 1.0*S/n;
    printf("%.2lf",s);

    return 0;
}