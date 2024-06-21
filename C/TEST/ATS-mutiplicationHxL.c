//高精度*低精度(默认前高后低)
#include <stdio.h>
#include <string.h>
int main()
{
    char s1[3000];//准备字符串，收集数字
    int b;
    scanf("%s\n%d",&s1,&b);
    int a[3000],c[3000];
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    int len = strlen(s1);
    int i,j;
    for(i=0,j=len-1;i<len;i++,j--)
    {
        a[i] = s1[j] - '0';
    }
    for(i=0;i<len;i++)
    {
        c[i] = a[i] * b;
    }
    int temp1,temp2;//temp1是商  temp2是余数





    for(i=0;i<3000;i++)
    {
        if(c[i]>=10)
        {
            temp1 = c[i]/10;
            temp2 = c[i]%10;
            c[i] = temp2;
            c[i+1] += temp1;
        }
    }


    
    i = 2999;
    while(c[i]==0 && i>0)
    {
        i--;
    }
    for(j=i;j>=0;j--)
    {
        printf("%d",c[j]);
    }
    return 0;
}