#include<stdio.h>

struct NUM
{
    int flag;
    int value;
};

static struct NUM arr[99];

int PartialSum(const int n,const int k,const int position)
{
    int i,x;
    for(i=0;i<n;i++)
    {
        x = k - arr[i].value;
        if(x == 0)
        {
            arr[i].flag = 1;
            return 1;
        }
        else if(i == (n-1))
        {
            return 0;
        }
    }
}
int main(){

    int t,n,k,x;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d %d",&n,&k);
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",arr[i].value);
        }
        x = PartialSum(n,k,0);
        if(x == 0)
        {
            printf("NO");
        }
        else
        {
            for(i=0;i<99;i++)
            {
                if(arr[i].flag == 1)
                {
                    printf("%d",arr[i].value);
                }
            }
        }
        t--;
    }

    return 0;
}