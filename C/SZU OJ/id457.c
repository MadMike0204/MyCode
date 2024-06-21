#include<stdio.h>
#include<string.h>

void buyC(int allcount,int money);

int main(){

    int t;
    int allcount,money;

    scanf("%d",&t);
    
    while(t>0)
    {
        scanf("%d %d",&allcount,&money);
        buyC(allcount,money);
        t--;
    }

    return 0;
}

void buyC(int allcount,int money)
{
    int i,j,k;
    int male,female,little,resultcount=0;
    int result[20][3];
    memset(result,0,sizeof(result));
    for(i=1;i<=money/5;i++)
    {
        for(j=1;j<=(money-i*5)/3;j++)
        {
            for(k=3;k<=(money-i*5-j*3)*3;k+=3)
            {
                if(i*5 + j*3 + (k/3) == money && (i+j+k) == allcount)
                {
                    result[resultcount][0] = i;
                    result[resultcount][1] = j;
                    result[resultcount][2] = k;
                    resultcount++;
                }
            }
        }
    }
    printf("%d\n",resultcount);
    for(i=0;i<resultcount;i++)
    {
        printf("%d %d %d\n",result[i][0],result[i][1],result[i][2]);
    }
    return;
}