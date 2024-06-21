#include<stdio.h>
int main(void){

    int n,w;
    scanf("%c",&n);
    w = n%2;
    if(w) printf("YES");
    else printf("NO");

    return 0;
}