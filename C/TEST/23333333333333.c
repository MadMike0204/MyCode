#include<stdio.h>
int main(){

        int i,j,n,m;
        int arr[20][10];
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

    return 0;
}