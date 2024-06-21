#include<stdio.h>
#include<string.h>
void ATS_ADD(char *s1,char *s2)
{
    static int result[10000];
    int a[3000],b[3000];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(result,0,sizeof(result));
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int i,j;
    for(i=0,j=l1-1;i<l1;i++,j--)
    {
        a[i] = s1[j] - '0';
    }

    for(i=0,j=l2-1;i<l2;i++,j--)
    {
        b[i] = s2[j] - '0';
    }
    int len = 0;
    if(l1>l2)
    {
        len = l1;
    }
    else
    {
        len = l2;
    }
    for(i=0;i<len;i++)
    {
        result[i] = a[i] + b[i];
    }
    for(i=0;i<len;i++)
    {
        if(result[i]>=10)
        {
            result[i+1] += result[i]/10;
            result[i] %= 10;
        }
    }
    i = 2999; 
    while(result[i]==0 && i>0)
    {
        i--;
    }
    for(j=i;j>=0;j--)
    {
        printf("%d",result[j]);
    }
}
int main(){

    char s10[3000],s20[3000];
    memset(s10,0,sizeof(s10));
    memset(s10,0,sizeof(s10));
    scanf("%s",&s10);
    scanf("%s",&s20);
    ATS_ADD(s10,s20);

    return 0;
}