#include<stdio.h>
#include<string.h>
int main(){

    int t;
    char str[31];
    scanf("%d",&t);
    while(t>0)
    {
        memset(str,0,sizeof(str));
        scanf("%s",str);
        int i;
        for(i=0;i<31;i++)
        {
            if(str[i] == 0)
                break;
        }
        
        printf("%d\n",i);
        t--;
    }

    return 0;
}