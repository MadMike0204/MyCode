#include<stdio.h>
int main(){

    int T;
    scanf("%d",&T);
    int n,sum;
    int i,j;
    int temp;
    while(T>0)
    {
        scanf("%d",&n);
        sum = 0;
        T--;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&temp);
                if(i == j)
                    sum += temp;
                else 
                    continue;
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}