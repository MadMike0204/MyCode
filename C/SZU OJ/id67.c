#include<stdio.h>
int main(){

    int a,b,c,d,e,f;
    scanf("%d/%d/%d/",&a,&b,&c);
    getchar();
    scanf("%d/%d/%d/",&d,&e,&f);
    if((a+b+c)%2 == (d+e+f)%2)
        printf("YES");
    else 
        printf("NO");

    return 0;
}