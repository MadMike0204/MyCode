#include<stdio.h>
int main(){

    int arr[10][10];
    int i,j;
    int n,m;

        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++)
        {
            for(i=0;i<m;i++)
            {
                scanf("%d",&arr[j][i]);
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf(j==0 ? "%d":" %d",arr[j][i]);
            }
            printf("\n");
        }



    return 0;
}