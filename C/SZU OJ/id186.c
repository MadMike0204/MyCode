#include<stdio.h>
int main(){


    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    int x5,y5,x6,y6;
    int x7,y7,x8,y8;
    int bol=0,T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        scanf("%d %d %d %d\n",&x1,&y1,&x3,&y3);
        scanf("%d %d %d %d",&x5,&y5,&x7,&y7);
        x4 = x1;
        x2 = x3;
        y4 = y3;
        y2 = y1;
        x6 = x7;
        x8 = x5;
        y6 = y5;
        y8 = y7;
        if(x5<=x3 && x5>=x4 && y5<=y3 && y5>=y2)
            bol = 1;
        if(x6<=x3 && x6>=x4 && y6<=y3 && y6>=y2)
            bol = 1;
        if(x7<=x3 && x7>=x4 && y7<=y3 && y7>=y2)
            bol = 1;
        if(x8<=x3 && x8>=x4 && y8<=y3 && y8>=y2)
            bol = 1;
        if(bol)
            printf("YES\n");
        else
         printf("NO\n");

    }


    
    return 0;
}