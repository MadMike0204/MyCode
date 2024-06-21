#include<stdio.h>
#include<string.h>
int main(){

    int num[10],i,T,aim,isexist,n2[10],a,bit;
    scanf("%d",&T);
    while(T)
    {
        a = 0;
        memset(num,9999,sizeof(num));
        isexist = 0;
        for(i=0;i<10;i++)
        {
            scanf("%d",&num[i]);
        }
        scanf("%d",&aim);
        for(i=0;i<10;i++)
        {
            if(num[i] != aim)
            {
                n2[a] = num[i];
                a++;
            }
            if(aim == num[i])
                isexist = 1;
        }
        if(isexist)
        {
            for(i=0;i<a;i++)
            {
                printf(i==0? "%d":" %d",n2[i]);
            }
            printf("\n");
        }
        else
            printf("Not found\n");
        T--;
    }

    return 0;
}