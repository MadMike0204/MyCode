#include<stdio.h>
float fun(int x,int y)
{  return (x+y);}
void main()
{   int a=2,b=5,c=8;
    printf("%3.0f\n",fun((int)fun(a+c,b),a-c));
}