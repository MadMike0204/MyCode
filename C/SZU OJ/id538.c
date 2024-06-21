/*
题目描述
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
输入
输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，
每行包含一个整数M（1<M<=40）,表示楼梯的级数。
输出
对于每个测试实例，请输出不同走法的数量
*/
#include<stdio.h>

int SuperStairs(const int M);

int main(){

    int t,M;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d",&M);
        printf("%d\n",SuperStairs(M-1));
        t--;
    }

    return 0;
}

int SuperStairs(const int M)
{
    if(M == 1)
    {
        return 1;
    }
    else if(M == 2)
    {
        return 2;
    }
    else if(M == 0)
    {
        return 0;
    }
    return SuperStairs(M-1)+SuperStairs(M-2);
}