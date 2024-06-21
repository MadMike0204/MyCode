#include<stdlib.h>
#include<stdio.h>
int swap(int* x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return 0;
}
int main(){

    int T;
    scanf("%d",&T);
    int arr[10];
    int j,i;
    while(T != 0)
    {
        for(i=0;i<10;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=0;i<10;i++)
        {
            for(j=i+1;j<10;j++)
            {
                if(arr[j]<arr[i])
                    swap(arr+i,arr+j);
            }
        }
        for(i=0;i<10;i++)
        {
            printf(i==0?"%d":" %d",arr[i]);
        }
        printf("\n");
        T--;
    }

    return 0;
}