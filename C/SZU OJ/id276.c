#include<stdio.h>
int main(){

    int n[10],count;
    int i,T;
    scanf("%d",&T);
    while(T)
    {
        count = 0;
        for(i=0;i<10;i++)
        {
            scanf("%d",&n[i]);
            if(n[i] < 0)
                count++;
        }
        printf("%d\n",count);
        T--;
    }

    return 0;
}