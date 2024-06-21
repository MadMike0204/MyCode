#include<stdio.h>
int main(){

    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    int arr[n][m];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%c",&arr[i][j]);
            getchar();
        }
    }
    for(j=0;j<m;j++)
    {
        for(i=n-1;i>=0;i--)
        {
            printf(i==(n-1)?"%c":" %c",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}