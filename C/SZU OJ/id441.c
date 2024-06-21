#include<stdio.h>
#include<string.h>
int main(){

    int t;
    scanf("%d",&t);
    int i,j;
    char str[101];
    memset(str,0,sizeof(str));
    int count[3];
    while(t>0)
    {
        memset(count,0,sizeof(count));
        memset(str,0,sizeof(str));
        scanf("%s",str);
        for(i=0;i<100;i++)
        {
            switch(str[i])
            {
                case '0'...'9':
                    count[1]++;
                    break;
                case 'A'...'Z':
                case 'a'...'z':
                    count[0]++;
                    break;
                case '\000':
                    break;
                default:
                    count[2]++;
            }
        }
        printf("%d %d %d\n",count[0],count[1],count[2]);
        t--;
    }
    
    return 0;
}