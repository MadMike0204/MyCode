
#include <stdio.h>
 
int main()
{
	int n;
	scanf("%d",&n);
	int a[100][100] = {0};
	int i,j; 
	int h = 1,t = n/2+1;
	
	a[1][t] = 1;
	for(i = 2; i <= n*n; i++)
	{
		if(h==1 && t!=n)
		{
			h = n;
			t++;
			a[h][t] = i;	
		}
		else if(t==n && h!=1)
		{
			h--;
			t = 1;
			a[h][t] = i;
		}
		else if(h==1 && t==n)
		{
			h++;
			a[h][t] = i;
		}
		else if(h!=1 && t!=n)
		{
			if(a[--h][++t]==0)
			{
				a[h][t] = i;
			}
			else
			{
				h = h + 2;
				t--;
				a[h][t] = i;
			}
		}
	}
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			printf(j==1?"%d":" %d",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}