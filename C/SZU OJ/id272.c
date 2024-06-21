#include<stdio.h>
int main(){

    int arr1[6],arr2[8];
    int i,j;
    int max = -9999;
    int T;
    for(i=0;i<6;i++)
    {
        scanf("%d",&arr1[i]);
        if(arr1[i] > max)
        {
            T = i;
            max = arr1[i];
        }
    }
    for(i=0;i<8;i++)
    {
        scanf("%d",&arr2[i]);
    }
    for(i=0;i<6;i++)
    {
        for(j=0;j<8;j++)
        {
            if(arr1[i] == arr2[j])
                printf("%d\n",arr1[i]);
        }
    }


    return 0;
}