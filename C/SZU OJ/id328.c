#include<stdio.h>

static int n;
static int result[999];


int main()
{
    static int i,j,clip,flag,count,isprint = 0;
    scanf("%d",&n);
    for(i=1;i<=(n/2+1);i++)
    {
        flag = 0;
        count = 0;
        clip = n;
        for(j=i;j<=(n/2+1) && clip >= 0;j++)
        {
            if(clip == j)
            {
                flag = 1;
            }
            clip -= j;
            result[count] = j;
            count++;
            if(flag)
            {
                break;
            }
        }
        if(flag == 1 && count >= 2)
        {
            for(j=0;j<count;j++)
            {
                printf(j==0?"%d":" %d",result[j]);
            }
            printf("\n");
            isprint = 1;
        }
    }
    if(isprint == 0)
    {
        printf("NULL");
    }
    return 0;
}
