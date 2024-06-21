/*id:44】【30分】A. 求最大值最小值（引用）
时间限制
1s
内存限制
128MB
题目描述

编写函数void find(int *num,int n,int &minIndex,int &maxIndex)，求数组num(元素为num[0]，num[1]，...，num[n-1]）中取最小值、最大值的元素下标minIndex,maxIndex（若有相同最值，取第一个出现的下标。）

输入n，动态分配n个整数空间，输入n个整数，调用该函数求数组的最小值、最大值下标。最后按样例格式输出结果。

改变函数find功能不计分。


输入

测试次数

每组测试数据一行：数据个数n，后跟n个整数


输出

每组测试数据输出两行，分别是最小值、最大值及其下标。具体格式见样例。多组测试数据之间以空行分隔。*/

#include <iostream>
using namespace std;

void ffind(int* num,int n,int &minindex,int &maxindex)
{
    int max = -9999,min = 9999;
    int maxind,minind;
    for(int i=0;i<n;i++)
    {
        if(*(num+i) > max)
        {
            max = *(num+i);
            maxind = i;
        }
        if(*(num+i) < min)
        {
            min = *(num+i);
            minind = i;
        }
    }
    maxindex = maxind;
    minindex = minind;
}

int main(){

    int n,t;
    int min = 0,max = 0;  
    cin >> t;
    while(t>0)
    {   
        cin >> n;
        int num[n];
        for(int i=0;i<n;i++)
        {
            cin >> num[i];
        }
        ffind(num,n,min,max);
        cout << "min=" << num[min] << " minindex=" << min << endl
             << "max=" << num[max] << " maxindex=" << max << endl;
        t--;
        if(t)
        {
            printf("\n");
        }
    }

    return 0;
}