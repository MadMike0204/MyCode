#include<stdio.h>
int main(void){
    int x,y,a,b;
    scanf("%d %d %d %d",&x,&a,&y,&b);
    double k;
    k = (double) (y*b-x*a)/(b-a);
    printf("%.2f",k);
    return 0;
}
//不通过的原因：如果希望得到浮点数的结果，两个运算数必须至少有一个浮点数，这时 C 语言就会进行浮点数除法。