#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){

    int zs[9600];
    memset(zs,0,sizeof(zs));
    int i,j,isPrime,n=0;
    for(i=2;i<=100000;i++)
    {
        isPrime = 1;
        for(j=2;j<=(int)sqrt(i);j++)
        {
            if(i%j == 0)
                isPrime = 0;
        }
        if(isPrime)
        {
            zs[n] = i;
            n++;
        }
    }

    int x,T,isEqual,isSym;
    scanf("%d",&T);
    char num[12];
    int bit;
    memset(num,0,sizeof(num));
    for(j=0;j<T;j++)
    {
        isEqual = 0;
        isSym = 1;
        scanf("%d",&x);
        for(i=0;;i++)
        {
            if(x == zs[i])
            {
                isEqual = 1;
            }
            if(x < zs[i])
            {
                break;
            }
        }
        if(isEqual)
        {
            for(i=0;;i++)
            {
                num[i] = x%10;
                x /= 10;
                if(x == 0)
                    break;
            }
            bit = i+1;
            for(i=1;i<(bit/2);i++);
            {
                if(num[i-1] != num[bit-i])
                    isSym = 0;
            }
        }
        if(isEqual && isSym)
            printf("Yes\n");
        else   
            printf("No\n");
    }
    return 0;
}