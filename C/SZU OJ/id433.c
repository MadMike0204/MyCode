#include<stdio.h>
#include<string.h>
int main(){

    int count[15];
    memset(count,0,sizeof(count));
    char str[15][15];
    memset(str,0,sizeof(str));
    char temp[15];
    int i,j,n=0,ishave;
    while(1)
    {
        ishave = 0;
        memset(temp,0,sizeof(temp));
        scanf("%s",temp);
        if(temp[0] == '0')
            break;
        else
        {
            for(i=0;i<n;i++)
            {
                if(!strcmp(temp,str[i]))
                {
                    ishave = 1;
                    count[i]++;
                    break;
                }
            }
            if(!ishave)
            {
                for(i=0;i<15;i++)
                {
                    if(temp[i] == 0)
                        break;
                    str[n][i] = temp[i];
                }
                count[n]++;
                n++;
            }
        }
    }
    int ban[15];
    int rank[15];
    int max;
    memset(ban,0,sizeof(ban));
    for(i=0;i<n;i++)
    {
        max = -999;
        for(j=0;j<n;j++)
        {
            if(count[j] > max && ban[j] != 1)
            {
                max = count[j];
                rank[i] = j;
            }
        }
        printf("%d %s\n",count[rank[i]],str[rank[i]]);
        ban[rank[i]] = 1;

    }

    return 0;
}