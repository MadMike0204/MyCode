#include<stdio.h>

int NumOperation(int x);
int SortStraight(int x);
int SortInvert(int x);

int main(){

    int n,count,t;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d",&n);
        printf("%d\n",NumOperation(n));
        t--;
    }

    return 0;
}

int NumOperation(int x)
{
    int i;
    int last = -9999;
    for(i=1;;i++)
    {
        last = x;
        x = SortInvert(x) - SortStraight(x);
        if(last == x)
            return i;
        if(i>100000)
            return -1;
    }
}
int SortStraight(int x)
{
    int arr[4],num,i,j,k,temp;
    for(i=0;i<4;i++)
    {
        arr[i] = x % 10;
        x /= 10;
    }
    for(i=0;i<4;i++)
    {
        k = i;
        for(j=i+1;j<4;j++)
        {
            if(arr[j] < arr[k])
                k = j;
        }
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
    num = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
    return num;
}
int SortInvert(int x)
{
    int arr[4],num,i,j,k,temp;
    for(i=0;i<4;i++)
    {
        arr[i] = x % 10;
        x /= 10;
    }
    for(i=0;i<4;i++)
    {
        k = i;
        for(j=i+1;j<4;j++)
        {
            if(arr[j] > arr[k])
                k = j;
        }
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
    num = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
    return num;
}