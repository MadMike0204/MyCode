#include<stdio.h>
int main(void){

    unsigned int n,k;
    scanf("%d %d",&n,&k);
    int num[n-1];
    int As,Bs;
    As = Bs = 0;
    int An=0,Bn=0;
    int i = 0;
    for(i=0;i<n;i++)
    {
        num[i] = i+1;
    }
    for(i=0;i<n;i++)
    {
        if(!(num[i]%k))
        {
            As = As + num[i];
            An++;
        }
        else
        {   
            Bs = Bs + num[i];
            Bn++;
        }
    }
    double A,B;
    A = 1.0*As/An;
    B = 1.0*Bs/Bn;
    printf("%.1lf %.1lf",A,B);

    return 0;
}