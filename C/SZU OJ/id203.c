#include<stdio.h>
int main(){

    int n;
    scanf("%d",&n);
    int arr[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        arr[i] = 1 + 2*i;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<(arr[n-1-i]/2);j++)
        {
            printf(" ");
        }
        for(j=0;j<arr[i];j++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}