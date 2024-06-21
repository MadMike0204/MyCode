#include<string.h>
#include<stdio.h>
int main(){

    int n;
    long long Num[49];
    memset(Num,0,sizeof(Num));
    Num[1] = 1;    
    scanf("%d",&n);
    if(n == 0) 
        printf("0.00");
    else 
        if(n == 1)
            printf("1.00");
        else
        {
            int i;
            for(i=2;i<=n;i++)
            {
                Num[i] = Num[i-1] + Num[i-2];   
            }
            printf("%lld.00",Num[n]);
        }
    


    return 0;
}
