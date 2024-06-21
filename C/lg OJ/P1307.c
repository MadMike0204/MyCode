#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void){

    long long int a,b;
    int bool = 0;
    scanf("%lld",&a);
    if(a<0) bool = 1;
    a = fabs(a);
    b = a;
    int Num[11];

    memset(Num,0,sizeof(Num));

    int i;

    for(i=10;i>=0;i--)
    {
        Num[i] = a%10;
        a /= 10;
    }

    i = 0;
    while(i<=10 && Num[i]==0)
    {
        i++;
    }

    int m;
    for(m=10;m>=i;m--)
    {
        if(Num[m] != 0) 
            break;   
    }

    if(bool)
        printf("-");
    int j;
    for(j=m;j>=i;j--)
    {
            printf("%d",Num[j]);
    }
    
    if(0 == b) 
        printf("0");

    return 0;
}