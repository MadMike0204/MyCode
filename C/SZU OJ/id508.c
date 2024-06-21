#include<stdio.h>
int comb(int a, int b);
/********** Write your code here! **********/
int comb(int a, int b)
{
    char num[4];
    num[0] = a % 10;
    a = a / 10;
    num[2] = a % 10;
    num[1] = b % 10;
    b = b / 10;
    num[3] = b % 10;
    int x = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
    return x;
}


/*******************************************/
int main() {
	int number1, number2, result;
	scanf("%d %d", &number1, &number2);
	result = comb(number1,number2);
	printf("%d", result);
	return 0;
}

