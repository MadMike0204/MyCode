#include <stdio.h>
int main()
{
	char x = '1';
	while(x != '\n')
	{
		scanf("%c",&x);
		printf("%c",x);
	}
}