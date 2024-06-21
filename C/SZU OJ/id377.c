//【id:377】【7分】H. 矩阵取数问题（数组）
// 动态规划
#include<stdio.h>
#include<string.h>

static int rect[500][500];
static int isNumEdited[500][500];
static int n;
 
int RectMaxVauleOnRoad(const int x,const int y);
void InputRect();
int Max2(const int x,const int y);

int main(){

    memset(isNumEdited,0,sizeof(isNumEdited));
    scanf("%d",&n);
    InputRect();
    printf("%d",RectMaxVauleOnRoad(n-1,n-1));
    return 0;
}

int RectMaxVauleOnRoad(const int x,const int y)
{  
    if(isNumEdited[x][y])
    {
        return rect[x][y];
    }
    int max,sum1,sum2;
    if(x == 0 && y == 0)
    {
        max = rect[0][0];
    }
    else if(x == 0 && y != 0)
    {
        max = rect[x][y] + RectMaxVauleOnRoad(x,y-1);
    }
    else if(y == 0 && x != 0)
    {
        max = rect[x][y] + RectMaxVauleOnRoad(x-1,y);
    }
    else
    {
        sum1 = rect[x][y] + RectMaxVauleOnRoad(x-1,y);
        sum2 = rect[x][y] + RectMaxVauleOnRoad(x,y-1);
        max = Max2(sum1,sum2);
    }
    isNumEdited[x][y] = 1;
    rect[x][y] = max;
    return max;
}

void InputRect()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&rect[i][j]);
        }
    }
}

int Max2(const int x,const int y)
{
    if(x > y)
        return x;
    else    
        return y;
}