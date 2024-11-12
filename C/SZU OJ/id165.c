#include<stdio.h>
int main(){

    int t; // t个测试实例
    scanf("%d",&t);

    int sum; // 满足条件的数值的数量
    int N;   // 数值上限
    while(t--){

        sum = 0; // 初始化数量
        scanf("%d",&N); // 输入数值上限
        
        for(int i=1;i<=N;i++){
            if(i % 3 != 0 && i % 4 != 0 && i % 7 == 0)
                sum++;    
        }

        printf("%d\n",sum);
    }

    return 0;
}