//DFS
#include<stdio.h>

static int arr[99];
static int n,r;//n=选择数的范围，r=需要选择多少个数

void DFS_CombinationNumbers(const int x,const int y);//x=选择数的范围，y=需要选择多少个数

int main()
{
    scanf("%d %d",&n,&r);
    DFS_CombinationNumbers(n,r);
    return 0;
}

void DFS_CombinationNumbers(const int x,const int y)
{
    int i;
    if(y == 0)//如果不需要再选了，就输出选好的数字（到达这一步就证明前面已经选好了）
    {
        for(i=r;i>0;i--)
        {
            printf("%d",arr[i]);//倒序遍历数组，输出需要的数
        }
        printf("\n");
        return;
    }
    else//如果还需要选，那么需要从上一次选择的数开始往下选择（进行递归）
    {
        for(i=x;i>=y;i--)
        {
            arr[y] = i;//y选好的数字存入数组，但是要注意是倒序 读取顺序是从 r--->1(选了几个数就会存几个数)
            DFS_CombinationNumbers(i-1,y-1);//i-1即选择数的范围是上一层选择好的数-1 y-1说明选好了一个数
        }
    }
}