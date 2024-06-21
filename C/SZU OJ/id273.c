#include<stdio.h>
int main(){

    int arr1[9],arr2[10];
    int i,j,x,count=0;
    for(i=0;i<9;i++)
    {
        scanf("%d",&arr1[i]);
    }
    scanf("%d",&x);
    for(i=0;i<8;i++)
    {
        if(x > arr1[i] && x < arr1[i+1])
        {
            count = i+1;
        }
        else if(x<arr1[i] && x>arr1[i+1])
        {
            count = i+1;
        }
    }
    for(i=0;i<10;i++)
    {
        if(i == count)
            arr2[i] = x;
        else if(i<count)
            arr2[i] = arr1[i];
        else if(i>count)
            arr2[i] = arr1[i-1];
    }
    for(i=0;i<10;i++)
    {
        printf("%d\n",arr2[i]);
    }

    return 0;
}