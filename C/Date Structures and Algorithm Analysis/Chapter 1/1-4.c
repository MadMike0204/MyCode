#include<stdio.h>
void PrintDigit(unsigned int N)
{
    printf("%d",N);
}
void PrintOut(unsigned int N)
{
    if(N >= 10)
        PrintOut(N / 10);
    PrintDigit(N % 10);
}
int main(){


    return 0;
}