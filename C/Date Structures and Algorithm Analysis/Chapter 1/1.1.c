#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int swap(int* x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return 0;
}
int main(){

    const int k = 2;
    int n,m;
    scanf("%d",&n);
    int arr[n];
    int j,i;
    for(i=0;i<n;i++)
    {
        arr[i] = rand() % 10 + 0;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
                swap(arr+i,arr+j);
        }
    }
    m = arr[0];
    i=0,j=1;
    while(i != n-1)
    {
        
        if(j == k+1)
        {
            printf("%d %d\n",arr[i],i);
            break;
        }
        if(arr[i] != arr[i+1])
            j++;
        i++;
    }
    printf("%.2lfsec",clock()/(double)CLOCKS_PER_SEC);
    return 0;
}