#include<stdio.h>
int main(){

    int t,n,k,rzt,sum;
    scanf("%d",&t);
    int i,j,p;
    for(i=0;i<t;i++)
    {
        rzt = 1;
        sum = 0;
        scanf("%d %d",&n,&k);
        for(j=1;j<=k;j++)
        {
            rzt *= n;
            sum += rzt;
        }
        printf("%d\n",sum);
    }

    return 0;
}