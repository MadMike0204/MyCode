#include<stdio.h>
#include<math.h>

int main()
{
	int n,m,T;
	int sum=0,i=0,j=0,i0=0;
	double I;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		sum=0;
		i0=0;
		for(i=n;i<=m;i++)
		{
			I=sqrt(i);
			for(j=2;j<=I;j++)
			{
				if(i%j==0)
					break;
			}
			if(j>I&&i>=2&&i!=i0)
			{
				printf("%d ",i);
				sum+=i;
				i0=i;
			}
		}
		if(sum==0)
			printf("No\n");
		else
			printf("\n%d\n",sum);
	}
}