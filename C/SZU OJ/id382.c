#include<stdio.h>
int main(){

    int arr[10][10];
    int T,i,j;
    scanf("%d",&T);
    int n,sum,max;
    while(T>0)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&arr[j][i]);
            }
        }
        for(i=0;i<n;i++)
        {
            max = -9999;
            sum = 0;
            for(j=0;j<n;j++)
            {
                sum += arr[j][i];
                if(arr[j][i] > max)
                {
                    max = arr[j][i];
                }
            }
            printf("%d %d\n",max,sum);
        }
        T--;
    }


    return 0;
}