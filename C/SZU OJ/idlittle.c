#include<stdio.h>
int main()
{
	int a,b,c,i=1,k=1,j=1;
	float sum1,sum2,sum3,sum;
	scanf("%d%d%d",&a,&b,&c);
	while(i<=a)
	{
		sum1+=(i++);
	}
	while(k<=b)
	{
		sum2+=(k*k);
		++k;
	}
	while(j<=c)
	{
		sum3+=(1.00/j);
		++j;
	}
	sum=sum1+sum2+sum3;
	printf("%.2f",sum);
	return 0;		
}
//100 50 10 输出47977.93 
//10 10 10 输出 442.93