#include<stdio.h>
int main(){

    int n[10];
    int i,T,aim,isfound;
    scanf("%d",&T);
    while(T != 0)
    {
        isfound = 0;
        for(i=0;i<10;i++)
        {
            scanf("%d",&n[i]);
        }
        scanf("%d",&aim);
        for(i=0;i<10;i++)
        {
            if(aim == n[i])
            {
                isfound = 1;
                break;
            }
        }
        if(isfound)
            printf("%d\n",i);
        else   
            printf("Not found\n");
        T--;
    }
    return 0;
}