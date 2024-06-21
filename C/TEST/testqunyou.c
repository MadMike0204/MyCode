#include<stdio.h>
double sum(double s[], int b)
{
	int i = 0;
	int w = 0;
	for (i = 0; i < b; i++)
	{
		w = w + s[i];
	}
	printf("%d\n", w);
	return w;
}
double average( double num[5],int nums)
{
	double n = sum(num, nums);
	printf("%d\n", n);
	return n / nums;
}
int main()
{
	int r = 0;
	int len = 0;
	double grades[5] = { 1,2,3,4,5 };
	for (r = 0; r < 5; r++)
	{
		scanf("%lf", &grades[r]);
	}
	len = sizeof(grades) / sizeof grades[0];
	average(grades, len);
	printf("该同学的平均成绩为%lf\n", average);
	return 0;
}