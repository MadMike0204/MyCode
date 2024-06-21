#include<stdio.h>
int main(){

    int n,S=0;
    scanf("%d",&n);
    int num[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]%2 == 0)
            S += num[i];
    }
    printf("%d",S);


    return 0;
}