#include<stdio.h>
#include<string.h>
int main()
{
	int min, len1, len2, len, a[100], b[100], tmp, i, j;
	scanf("%d", &len1);
	for (i = 0; i<len1; i++)
		scanf("%d", &a[i]);
	scanf("%d", &len2);
	for (i = 0; i<len2; i++)
		scanf("%d", &b[i]);
/********** Write your code here! **********/    
    len = len1 + len2;
	int c[1000];
	int T;
    T = 0,i = 0,j = 0;
	while(T < len)
	{
		if(len1 == i)
		{
			c[T] = b[j];
			j++;
		}
		else if(len2 == j)
		{
			c[T] = a[i];
			i++;
		}
		else if(a[i] >= b[j])
		{
			c[T] = b[j];
			j++;
		}
		else if(a[i] < b[j])
		{
			c[T] = a[i];
			i++;
		}
		T++;
	}
	for(i=0;i<len;i++)
	{
		b[i] = c[i];
	}
/*******************************************/
	for (i = 0; i<len; i++)
		printf("%d ", b[i]);
	return 0;
}