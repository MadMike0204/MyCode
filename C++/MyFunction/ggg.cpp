

int ged(int a1, int a2)//最大公倍数
{
	int flag;
	if (a1 == 0 || a2 == 0)
		return 0;
	if (a1 < a2)
	{
		flag = a1;
		a1 = a2;
		a2 = flag;
	}//这样必定使a1>n
	while (a2 != 0)//辗转相除
	{
		flag = a1 % a2;
		a1 = a2;
		a2 = flag;
	}
	return a1;
}
