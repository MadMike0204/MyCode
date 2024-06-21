#include<stdio.h>
int main(){

    int arr[20];
    int i,j;
    for(i=0;i<20;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<20;i++)
    {
        for(j=0;j<20 && j != i;j++)
        {
            if(arr[i]%arr[j] == 0)
            {
                printf("%d\n",arr[i]);
                break;
            }
        }
    }

    return 0;
}