#include<stdio.h>
int Fibonacci(unsigned n)
{
    if (n >= 2)
        return Fibonacci(n - 1);
    else
        return 1;
}
int main(){

    double sum=0;
    int n;
    scanf("%d",&n);
    int i;
    double temp1,temp2;
    for(i=1;i<=n;i++)
    {
        temp1 = (double)Fibonacci(i);
        temp2 = (double)Fibonacci(i+1);
        sum += 1.0*temp2/temp1;
    } 
    printf("%lf",sum);
    return 0;
}