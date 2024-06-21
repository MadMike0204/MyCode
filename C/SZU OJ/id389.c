#include<stdio.h>
int main(){

    int t;
    scanf("%d",&t);
    int n,m,i,j;
    getchar();
    int arr[23][23];
    while(t>0)
    {
        scanf("%d %d",&n,&m); 
        getchar();   
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%c",&arr[i][j]);
                getchar();
            }
        }
        for(j=m-1;j>=0;j--)
        {
            for(i=0;i<n;i++)
            {
                printf(i==0?"%c":" %c",arr[i][j]);
            }
            printf("\n");
        }
        t--;
    }
    
    return 0;
}