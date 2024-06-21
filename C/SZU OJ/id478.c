#include<stdio.h>
#include<string.h>

static int PrimeTable[1000];

void CreatePrimeTable();//需要操作的质数表 输出的质数个数
int isAprime(int x);//需要判断的数

int main(){

    int x,i,j,count = 0,isit,a,b;
    scanf("%d",&x);

    CreatePrimeTable();
    for(i=2;i<=x/2;i++)
    {
        a = i;
        b = x - i;
        if(isAprime(a) && isAprime(b))
            count ++;
    }
    printf("%d",count);

    return 0;
}

void CreatePrimeTable()//需要操作的质数表 输出的质数个数
{
    memset(PrimeTable,0,sizeof(PrimeTable));
    int i,j,isPrime,n=0;
    for(i=2;i<1600;i++)
    {
        isPrime = 1;
        for(j=2;j<=i/2;j++)
        {
            if(i%j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime)
        {
            PrimeTable[n] = i;
            n++;
        }
    }
}
int isAprime(int x)
{
    int i;
    for(i=0;i<200;i++)
    {
        if(x == PrimeTable[i])
            return 1;
    }
    return 0;
}