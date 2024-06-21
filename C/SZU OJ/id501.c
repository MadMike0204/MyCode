#include<stdio.h>

int whetherPrime(int x)
{
    int isPrime = 1;
    int i,j;
    if(x == 1)
    {
        printf("not prime");
        return 0;
    }
    else
    {
        for(i=2;i<=x/2;i++)
        {
            if(x%i == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime)
        {
            printf("prime");
            return 0;
        }
        else
        {
            printf("not prime");
            return 0;
        }
    }
    
}

int main(){

    int x;
    scanf("%d",&x);
    whetherPrime(x);

    return 0;
}