#include<stdio.h>
int main(){

    int T,a,b;
    int arr[10][10];
    scanf("%d",&T);
    int i,j;
    while(T>0)
    {
        scanf("%d %d",&a,&b);
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        for(i=0;i<b;i++)
        {
            for(j=0;j<a;j++)
            {
                printf(j==0? "%d":" %d",arr[j][i]);
            }
            printf("\n");
        }
        
        T--;
    }


    return 0;
}