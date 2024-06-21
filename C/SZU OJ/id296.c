#include<stdio.h>
int main(){

    int T,arr[8],arr2[8];
    scanf("%d",&T);
    int i,j,n;
    for(i=0;i<T;i++)
    {
        n=0;
        for(j=0;j<8;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=0;j<8;j++)
        {
            if(arr[j]<0)
            {
                arr2[n] = arr[j];
                n++;
        }
        }
                for(j=0;j<8;j++)
        {
            if(arr[j]==0)
            {
                arr2[n] = arr[j];
                n++;
            }
        }
                for(j=0;j<8;j++)
        {
            if(arr[j]>0)
            {
                arr2[n] = arr[j];
                n++;
        }
        }
        for(j=0;j<8;j++)
        {
            printf("%d",arr2[j]);
        }
        printf("\n");
    }


    return 0;
}