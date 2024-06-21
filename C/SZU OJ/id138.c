#include<stdio.h>
int main(){

   int T;
   scanf("%d",&T);
   int i,j;
   int n,haveyz,sum;
   int yz[15],x;
   for(i=0;i<T;i++)
   {
        haveyz = x = sum = 0;
        scanf("%d",&n);
        for(j=1;j<n;j++)
        {
            if(n%j == 0)
            {
                yz[x] = j;
                sum += yz[x];
                x++;
            }
        }
        if(sum == n)
        {
            printf("yes,");
            for(j=0;j<x-1;j++)
            {
                printf("%d,",yz[j]);
            }
            printf("%d\n",yz[x-1]);
        }
        else 
        {
            printf("no,");
            for(j=0;j<x-1;j++)
            {
                printf("%d,",yz[j]);
            }
            printf("%d\n",yz[x-1]);
        }
   } 

    return 0;
}