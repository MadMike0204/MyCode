#include<stdio.h>
#include<string.h>
int main(){

    int x,y;
    scanf("%d",&x);
    int arr1[x];
    memset(arr1,0,sizeof(arr1));
    int i,j;
    for(i=0;i<x;i++)
    {
        scanf("%d",&arr1[i]);
    }

    scanf("%d",&y);
    int arr2[y];
    memset(arr2,0,sizeof(arr2));
    for(i=0;i<y;i++)
    {

        scanf("%d",&arr2[i]);
    }
    int temp1,flag,k;
    for(i=0;i<x;i++)
    {
        flag = 0;
        for(j=0;j<y;j++)
        {
            if(arr1[i] == arr2[j])
            {
                temp1 = arr1[i];
                arr1[i] = -9999;
                arr2[j] = -9999;
                flag = 1;
            }
            if(flag)
            {
                for(k=0;k<x;k++)
                {
                    if(arr1[k] == temp1)
                    {
                        arr1[k] = -9999;
                    }
                }
                for(k=0;k<y;k++)
                {
                    if(arr2[k] == temp1)
                    {
                        arr2[k] = -9999;
                    }
                }
            }
        }


    }
    int count = 0;
    int m = x+y;
    int result[m];
    while(1)
    {
        for(i=0;i<x;i++)
        {
            if(arr1[i] != -9999)
            {
                result[count] = arr1[i];
                count++;
            }
        }
        for(i=0;i<y;i++)
        {
            if(arr2[i] != -9999)
            {
                result[count] = arr2[i];
                count++;
            }
        }
        if(i == y)
            break;
    }
    int max;
    for(i=0;i<count;i++)
    {
        max = -9999;
        k = i;
        for(j=i;j<count;j++)
        {
            if(max < result[j])
            {
                max = result[j];
                k = j;
            }
        }
        result[k] = result[i];
        result[i] = max;
    }
    if(count == 0)
    {
        printf("NULL\n");
    }
    else
    {
    for(i=0;i<count;i++)
    {
        printf(i==0?"%d":" %d",result[i]);
    }
    }





    return 0;
}