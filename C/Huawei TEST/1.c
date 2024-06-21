#include <stdio.h>
int main(void){
    int a,b,c,d;//c a小时 b d分钟
    a=b=c=d=0;
    scanf("%d %d %d %d/n",&a,&b,&c,&d);
    int Sum = d-b+(c-a)*60;
    int Th,Tm;
    Tm = Sum % 60;
    Th = (Sum - Tm)/60;
    printf("%d %d\n",Th,Tm);
    return 0;
}