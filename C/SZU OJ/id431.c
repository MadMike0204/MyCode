#include<stdio.h>
#include<string.h>

void SortInvert(int A[][21],N)
{
    int i,j;
    for(j=0;j<n;j++)
    {
        for(i=0;i<n-1;i++)
        {
            if(c[i][0] == c[i+1][0])
            {
                
            }
            else if(c[i][0] < c[i+1][0])
            {
                strcpy(temp,c[i]);
                strcpy(c[i],c[i+1]);
                strcpy(c[i+1],temp);
            }
        }
    }


    return 0;
}

int main(){

    int t,n;
    int i,j;
    char c[10][21];
    char temp[21];
    scanf("%d",&t);
    while(t>0)
    {
        memset(temp,0,sizeof(temp));
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",c[i]);
        }
        for(j=0;j<n;j++)
        {
            for(i=0;i<n-1;i++)
            {
                if(c[i][0] < c[i+1][0])
                {
                    strcpy(temp,c[i]);
                    strcpy(c[i],c[i+1]);
                    strcpy(c[i+1],temp);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            printf(i==0 ? "%s":" %s",c[i]);
        }
        printf("\n");
        t--;
    }

    return 0;
}