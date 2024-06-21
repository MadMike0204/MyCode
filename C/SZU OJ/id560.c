#include<stdio.h>
int main(){

    int t,i;
    char str[999];
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%s",str);
        for(i=0;i<999;i++)
        {
            if(str[i] == 0)
            {
                break;
            }
        }
        printf("%d\n",i);
        t--;
    }

    return 0;
}