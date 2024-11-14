#include<stdio.h>
int main(){

    int i,m,n=0,sum1=0,sum2=0;
    for(i=1;i<=12;i++)
    {
        scanf("%d",&m);
        sum1 = sum1 +300 - m;
        if(sum1<0)
        {
            printf("-%d",i);
            return 0;
        }
        if(sum1 >= 100)
        {
            n = (sum1/100)*100;
            sum1 -= n;
            sum2 += n;
        }
    }
    printf("%d",(int)(sum2*1.2+sum1));


    return 0;
}