#include<stdio.h>
#include<string.h>
int main(){

    int num[20],T,fully[9],last1[9],last2[9],i,n,a,b,c,t,is1,is2,is3;
    scanf("%d",&T);
    memset(num,0,sizeof(num));
    memset(fully,0,sizeof(fully));
    memset(last1,0,sizeof(last1));
    memset(last2,0,sizeof(last2));
    while(T)
    {
        is1=0,is2=0,is3=0;
        a=0,b=0,c=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        for(i=0;i<n;i++)
        {
            if((num[i]%3) == 0)
            {
                fully[a] = num[i];
                a++;
            }
            else if(num[i]%3 == 1)
            {
                last1[b] = num[i];
                b++;
            }
            else if(num[i]%3 == 2)
            {
                last2[c] = num[i];
                c++;
            }
        }
        t = a-1;
        for(a=a-1;a>=0;a--)
        {
            printf(a==t?"%d":" %d", fully[a]);
            is1 = 1;
        }
        if(!is1)
            printf("-1");
        printf("\n");
        t = b-1;
        for(b=b-1;b>=0;b--)
        {
            printf(b==t?"%d":" %d", last1[b]);
            is2 = 1;
        }
        if(!is2)
            printf("-1");
        printf("\n");
        t = c-1;
        for(c=c-1;c>=0;c--)
        {
            printf(c==t?"%d":" %d", last2[c]);
            is3 = 1;
        }
        if(!is3)
            printf("-1");
        printf("\n");
        T--;
    }

    return 0;
}