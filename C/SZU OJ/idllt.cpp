#include<stdio.h>
int main()
{
    int n,i,a=100,b,c,d;
    scanf("%d",&n);
    for(i = 100;i<=n;i++)
    {
        a++;
        b = a%10;
        c = a/10%10;
        d = a/100;
        if(a == b*b*b +c*c*c + d*d*d)
        {
            printf("%d\n",a);
        }
    }
    return 0;
}