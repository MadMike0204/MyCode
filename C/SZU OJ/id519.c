#include<stdio.h>

int AmicableNum(int x,int y)
{
    if(x == y)
        return 0;
    int sum1 = 0,sum2 = 0;
    int i;
    for(i=1;i<=x/2;i++)
    {
        if(x%i == 0)
        {
            sum1 += i;
        }
    }
    for(i=1;i<=y/2;i++)
    {
        if(y%i == 0)
        {
            sum2 += i;
        }
    }
    if(sum1 == y && sum2 == x)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int main(){


    int a,b,t;
    scanf("%d",&t);
    while(t > 0)
    {
        scanf("%d %d",&a,&b);
        if(AmicableNum(a,b))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        t--;
    }


    return 0;
}