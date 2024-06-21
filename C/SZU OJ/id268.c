#include<string.h>
#include<stdio.h>
int main(){

    int n;
    scanf("%d",&n);
    int arr[n+1];
    memset(arr,0,sizeof(arr));
    int i,j;
    int count = n,x = 0,winner;
    while(count != 0)
    {
        for(i=1;i<=n;i++)
        {
            if(arr[i] == -1)
                continue;
            x++;
            if(count == 1)
            {
                winner = i;
                count--;
                break;
            }
            x %= 3;
            if(x == 0)
            {
                arr[i] = -1;
                count--;
                printf("%d ",i);
            }
            if(arr[i] == -1)
                continue;
        }
    }
    printf("\n%d",winner);

    return 0;
}