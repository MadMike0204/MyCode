#include<stdio.h>
int main(){

    int a,b;
    scanf("%d %d",&a,&b);
    if(a >= 10 || b >=20)
        printf("1");
    else    
        printf("0");

    return 0;
}