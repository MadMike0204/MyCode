#include<stdio.h>
#include<string.h>
int isPalindrome(const char s[]);
int main(){

    int t;
    char str[44];
    scanf("%d",&t);
    while(t>0)
    {
        memset(str,0,sizeof(str));
        scanf("%s",str);
        if(isPalindrome(str))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        t--;
    }

    return 0;
}

int isPalindrome(const char s[])
{
    int i,len,flag = 1;
    for(i=0;;i++)
    {
        if(s[i] == 0)
            break;
    }
    len = i;
    for(i=0;i<len;i++)
    {
        if(i == (len-i-1))
            break;
        if(s[i] != s[len-i-1])
        {
            flag = 0;
        }
    }
    if(flag)
        return 1;
    else
        return 0;
}