#include<stdio.h>
#include<string.h>

int swap(int* x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return 0;
}

int main(){

    int n,count;
    int arr[100],is2[100];
    int i,T,j;
    scanf("%d",&T);
    while(T > 0)
    {
        count = 0;
        memset(is2,0,sizeof(is2));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]%2 == 0)
            {
                is2[i] = 1;
                count++;
            }
        }
        for(i=i-1;i>=count;i--)
        {
            if(is2[i])
            {
                for(j=0;j<n;j++)
                {
                    if(is2[j])
                        continue;
                    else 
                    {
                        swap(arr+i,arr+j);
                        swap(is2+i,is2+j);
                        break;
                    }
                }
            }
        }
        printf("%d ",n);
        for(i=0;i<n;i++)
        {
            printf(i==0?"%d":" %d",arr[i]);
        }
        printf("\n");
        T--;
    }
    return 0;
}