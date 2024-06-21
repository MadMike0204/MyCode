#include<stdio.h>
#include<math.h>
int main(void){

    int a,b;
    scanf("%d %d",&a,&b);
    long long S;
    S = pow(10,a)+b;
    printf("10^%d+%d = %lld",a,b,S);

    return 0;
}