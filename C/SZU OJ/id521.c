#include<stdio.h>

int a[100],k,n;
int path[100];
int pathLength;
//已经从前i项得到了和sum，i项之后的分支 
int dfs(int i,int sum){
    //如果前n项都计算过了，则返回sum是否与k相等 
    if(i==n) 
        return (sum == k);
    //不加上a[i]的情况 
    if(dfs(i+1,sum)) 
        return 1;
    //加上a[i]的情况 
    if(dfs(i+1,sum+a[i])) 
    {
        path[pathLength++] = a[i];
        return 1;
    }
    //加不加a[i]，都被无法与k相等，则返回false 
    //回溯 移除当前元素
    if(pathLength > 0)
        pathLength--;
    return 0;
} 

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        scanf("%d",&k);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        pathLength = 0;
        if(dfs(0,0)){
            printf("Yes\n");
            for(int i=pathLength-1;i>=0;i--)
            {
                printf(i==pathLength-1?"%d":" %d",path[i]);
            }
            printf("\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}