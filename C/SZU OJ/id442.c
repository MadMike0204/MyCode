#include<stdio.h>
#include<string.h>
int main(){

    char str[3][6] = {"Li","Zhang","Fu"};
    char temp[6];
    int score[3];
    memset(score,0,sizeof(score));
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%s",temp);
        for(j=0;j<3;j++)
        {
            if(!strcmp(str[j],temp))
            {
                score[j]++;
                continue;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        printf("%s:%d\n",str[i],score[i]);
    }

    return 0;
}