#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int x = a * b * c;
    int y =2 * (a*b + b*c + a*c);
    printf("V=%d\nS=%d\n",x,y);
    return 0;
}