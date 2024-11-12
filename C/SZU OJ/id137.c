#include<stdio.h>
int main(){

    float h,sum; // sum储存经过的距离，h为高度
    int n;
    scanf("%f %d",&h,&n); // 初始化高度

    for(int i=0;i<n;i++){

        if(i == 0)    // 第一次落地只有落下的距离，属于特殊情况
            sum += h; // 可以在循环中加if特判，
        else          // 也可以在循环外先计算第一次的结果
            sum += 2*h;
        sum = (int)((sum*1000+5)/10)/100.0; // 保留小数

        h /= 2; // h减半
        h = (int)((h*1000+5)/10)/100.0; // 保留小数
    }

    printf("%.2f\n%.2f",sum,h); // 输出结果

    return 0;
}