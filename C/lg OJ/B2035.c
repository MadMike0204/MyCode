#include<stdio.h>
int main(void){

    long long int N;
    scanf("%lld",&N);
    if(N>0)printf("positive");
    if(N<0)printf("negative");
    if(N==0)printf("zero");

    return 0;
}