#include<stdio.h>
double sum(double s[], int b)
{
	int i;
	int w = 0;
	for (i = 0; i < b; i++)
	{
		w = w + s[i];
	}
	printf("%d\n", w);
	return w;
}
double average(double num[],int nums)
{
	double n = sum(num, nums);
	printf("%lf\n", n);
	return (n / nums);
}
int main()
{
    double xbox[5];
    int x;
    for(x=0;x<5;x++)
    {
        scanf("%lf",&xbox[x]);
    }
    int b = 5;
    double ZZ = average(xbox,b);
    printf("%lf",ZZ);
    printf("%lf",average(xbox,b));
	return 0;
}