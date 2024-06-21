#include<stdio.h>
int main(void){

    int n;
    scanf("%d",&n);
    int i;
    int S = (n+1)*n/2;
    for(i=n;i>0;i--)//i记录行数
    {   
        int j;
        for(j=0;j<i;j++)//j记录本行要输出几个数
        {
            printf("%02d",S-i*(i+1)/2+j+1);//求出每个位置要输出的数
        }
        printf("\n");
    }

    return 0;
}