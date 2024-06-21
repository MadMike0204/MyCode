#include<stdio.h>
int main()
{
    int k;
    scanf("%d",&k);
    int i,j,s=2,bol,Sum=0,n=0;
    for(i=0;;i++)
    {
        bol=0;
        for(j=2;j<s;j++)
        {
            if(s%j==0 && s!=j) bol=1;
        }
        if(bol==0)
        {
            Sum += s;
            if(Sum>k) break;
            n++;
            printf("%d\n",s);
        }
        s++;
    }
    printf("%d",n);

    return 0;
}