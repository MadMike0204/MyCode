#include<stdio.h>
int main(){

    int y,m,d;
    char a,b;
    scanf("%d%c%d%c%d",&y,&a,&m,&b,&d);
    int k = y%m;
    int q = m%d;
    if(k==3&&q==3)
        printf("YES");
    else
        printf("NO");

    return 0;
}