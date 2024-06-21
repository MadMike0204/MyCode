#include<stdio.h>
int main(void){

    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int i=0;
    if((a+b+c)<=100)i++;
    if(!(b%5))i++;
    if(!(c%7))i++;
    if((a-b)>(b-c))i++;
    if(i == 4) printf("Yes");
    else printf("No");

    return 0;
}