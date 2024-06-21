#include<stdio.h>
#include<string.h>
int main(){

    int t,n,temp,isit;
    scanf("%d",&t);
    int i,j;
    int rect[20][20];
    int sum;// 0:行和 1:列和 2:对角线和
    while(t>0)
    {
        sum = 0;
        isit = 1;
        scanf("%d",&n);
//Part1
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&rect[i][j]);
            }
        }
//Part2
        for(j=0;j<n;j++)
        {
            sum += rect[j][0];
        }

//Part3-1
        for(j=1;j<n;j++)
        {
            temp = 0;
            for(i=0;i<n;i++)
            {
                temp = temp + rect[i][j];
            }
            if(temp != sum)
            {
                isit = 0;
                break;
            }
        }
//Part3-2
        temp = 0;
        if(isit)
        {
            for(j=1;j<n;j++)
            {
                temp = 0;
                for(i=0;i<n;i++)
                {
                    temp += rect[j][i];
                }
                if(temp != sum)
                {
                    isit = 0;
                    break;
                }
            }
        }
//Part3-3
        temp = 0;
        if(isit)
        {
            for(i=0;i<n;i++)
            {
                temp += rect[n-i-1][i];
            }
            if(temp != sum)
            {
                isit = 0;
            }
        }
//Part4
        if(isit)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        t--;
    }


    return 0;
}