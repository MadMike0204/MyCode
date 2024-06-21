#include<stdio.h>
int main(){

    int t,i,j;
    int rect[2][3];
    scanf("%d",&t);
    while(t>0)
    {
        for(i=0;i<2;i++)
        {
            for(j=0;j<3;j++)
            {
                scanf("%d",&rect[i][j]);
            }
        }
        int* To_rect = &rect[0][0];
        for(i=2;i>=0;i--)
        {
            for(j=0;j<2;j++)
            {
                printf("%d ",*(To_rect +j*3+i));
            }
            printf("\n");
        }
        t--;
    }

    return 0;
}