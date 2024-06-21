#include <stdio.h>
#include <string.h>
int main()
{
    char s1[3000],s2[3000];
    scanf("%s\n",&s1);
    scanf("%s",&s2);
    int a[3000],b[3000],c[6001];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int maxdigit = len1+len2;
    int i,j;
    for(i=0,j=len1-1;i<len1;i++,j--)
    {
        a[i] = s1[j] - '0';
    }
    for(i=0,j=len2-1;i<len2;i++,j--)
    {
        b[i] = s2[j] - '0';
    }



    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            c[i+j] += a[i] * b[j];
        }
    }




    int temp1,temp2;
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