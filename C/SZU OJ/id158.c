#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int t = 0;
	scanf("%d %d",&a,&b);
	int m = a;
	int n = b;
	while (a%b != 0){
		t = a%b;
		a = b;
		b = t;
	}
	printf("%d",b);
	printf("%d\n",m*n/b);
	return 0;
}