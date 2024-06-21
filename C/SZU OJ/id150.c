#include<stdio.h>
int main()
{
	int b=1;
    int i,x;
  	scanf("%d",&x);
	for (i = x; i>0; i--)
	{   
		b =2*(b + 1);
	}
	printf("%d", b);
	return 0;
}