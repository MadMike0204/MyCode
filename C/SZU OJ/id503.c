#include<stdio.h>

int Function(int x)
{
    if(x < 1)
    {
        return x;
    }
    else if(x >= 1 && x < 10)
    {
        return 2*x-1;
    }
    else if(x >= 10)
    {
        return 3*x-11;
    }
}

int main(){

    int n;
    scanf("%d",&n);
    printf("%d",Function(n));

    return 0;
}