#include<stdio.h>
int main() 
{
	float h,H,a;
	int n,i;
	scanf("%f%d",&h,&n);
	a = h,i = 1,H = h;
	
	while(i<n)
	{
		a = a/2;
		a = (int)((a*1000+5)/10)/100.0;
		H = H+a*2;
		H = (int)((H*1000+5)/10)/100.0;
		i++;
	}
	printf("%.2f\n%.2f\n",H,a);
	return 0;
}