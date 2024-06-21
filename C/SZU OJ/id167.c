#include<stdio.h>
int main(){

    int bol;
    int x,i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        bol = 0;
        scanf("%d",&x);
        if((x%6) == 0)
            bol = 1;
        if((x/100000)<10 && x >= 100000)
            bol = 1;
        if(((x-6)%10) == 0 && x>10)
            bol = 1;
        if(bol)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}