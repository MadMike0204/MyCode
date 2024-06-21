#include<stdio.h>
int main(){

    int c,r;
    scanf("%d %d",&r,&c);
    int rect[r][c];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&rect[i][j]);
        }
    }
    int(* To_rect)[c];
    To_rect = &rect[0];
    int max = -9999,min = 9999;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(*(*(To_rect+i)+j) > max)
            {
                max = *(*(To_rect+i)+j);
            }
            if(*(*(To_rect+i)+j) < min)
            {
                min = *(*(To_rect+i)+j);
            }
        }
    }
    printf("%d\n%d",max,min);

    return 0;
}