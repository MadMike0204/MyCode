#include<stdio.h>
int main(void){

    int n,w;
    scanf("%d",&n);
    w = n%2;
    if(w) printf("odd");
    else printf("even");

    return 0;
}