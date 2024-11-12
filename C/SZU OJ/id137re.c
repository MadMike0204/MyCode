#include<stdio.h>
int main(){

    float h,sum; // sum储存经过的距离，h为高度
    int n;
    scanf("%f %d",&h,&n); // 初始化高度

    sum +=h;
    sum = (int)((sum*1000+5)/10)/100.0; // 保留小数
    h /= 2; // h减半
    h = (int)((h*1000+5)/10)/100.0; // 保留小数

    for(int i=1;i<n;i++){

        sum += 2*h;
        sum = (int)((sum*1000+5)/10)/100.0; // 保留小数

        h /= 2; // h减半
        h = (int)((h*1000+5)/10)/100.0; // 保留小数
    }

    printf("%.2f\n%.2f",sum,h); // 输出结果

    return 0;
}