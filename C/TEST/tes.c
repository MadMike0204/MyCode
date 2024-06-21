#include<stdio.h>
int main()
{
 char str[20]="hello!\0world!\t\\\n";
 printf("%d %d\n",strlen(str),sizeof(str));
}