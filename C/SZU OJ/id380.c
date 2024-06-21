#include<stdio.h>

int DP_arrTower(int A[][100],int N)
{
    int i,j;
    for(i=N-2;i>=0;i--)
    {
        for(j=0;j<N-2;j++)
        {
            A[i+1][j] > A[i+1][j+1] ? (A[i][j] += A[i+1][j]) : (A[i][j] += A[i+1][j+1]);
        }
    }
    return A[0][0];
}

int main(){

    int arr[100][100];
    int C,n;
    scanf("%d",&C);
    int i,j;
    while(C>0)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        printf("%d\n",DP_arrTower(arr,n));
        C--;
    }

    return 0;
}