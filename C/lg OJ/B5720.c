#include<stdio.h>
#include<math.h>
int main(void){

    long long L;
    scanf("%lld",&L);
    long double temp = 0;
    temp = L;
    for(int i=0;;i++)
    { 
        if(temp==1) 
        {
            printf("%d",i+1);
            break;
        }
        temp = floorl(temp/2);
    }

    return 0;
}