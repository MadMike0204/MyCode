#include<stdio.h>
int main(){

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,a=1,b=0;
        scanf("%d",&N);
        while(a<=N)
        {
            if(a%3 != 0 && a%4 != 0 && a%7 == 0)
            {
                b++;
            }
            ++a;
        }
        printf("%d",b);
    }
    return 0;
}