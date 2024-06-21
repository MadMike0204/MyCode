#include<stdio.h>

char *substr(char *s,int startloc,int len)
{
    if(len <= 0)
    {
        return NULL;
    }
    int i;
    for(i=0;i<51;i++)
    {
        if(s[i] == 0)
        {
            break;
        }
    }
    if(len+startloc-1 > i && i > startloc)
    {
        char* To_str = &s[startloc-1];
        return To_str;
    }
    else if(len+startloc-1 <= i)
    {
        char* To_str = &s[startloc-1];
        s[startloc-1+len] = 0;
        return To_str;
    }
    else
    {
        return NULL;
    }
}

int main(){

    int t;
    scanf("%d",&t);
    int startloc,len;
    char str[51];
    while(t>0)
    {
        scanf("%s",str);
        getchar();
        scanf("%d %d",&startloc,&len);
        char* p = substr(str,startloc,len);
        if(p == 0)
        {
            printf("NULL\n");
        }
        else
        {
            printf(t==1?"%s":"%s\n",p);
        }
        t--;
    }

    return 0;
}