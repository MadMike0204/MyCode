#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){

    int zs[9600];
    memset(zs,0,sizeof(zs));
    int i,j,k,isPrime,n=0;
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

    int x,T,isEqual,isSym,rL,rR;
    scanf("%d",&T);
    char num[100000];
    int bit;
    memset(num,0,sizeof(num));
    int str[50];
    memset(str,0,sizeof(str));
    int have;

    for(j=0;j<T;j++)
    {
        have = 0;
        scanf("%d %d",&rL,&rR);
        for(k=rL;k<=rR;k++)
        {
            isEqual = 0;
            isSym = 1;
            for(i=0;i<9000;i++)
            {
                if(k == zs[i])
                {
                    isEqual = 1;
                    break;
                }
            }
            if(isEqual)
            {
                x = k;
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
            {
                printf("%d\n",k);
                have = 1;
            }
        }
        if(!have)
            printf("Not found\n");
    }
    return 0;
}