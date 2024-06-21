#include<stdio.h>
int main()
{
	char a,b,c,t;//定义字符abc和用来交换的字符t
	while(scanf("%c%c%c",&a,&b,&c)!=EOF)//当输入没有结束时
	{
		getchar();//用来吸收换行字符
	if(a>c)//如果a>c交换a和c的位置
	 {
	 	t=a,a=c,c=t;
	 }
	if(b>c)//如果b>c交换b和c的位置
	{
		t=b,b=c,c=t;
	 } 
	 //此时c是ASCII码最大的数
	 if(a>b)//如果a比b大，那么再次交换位置
	{
		t=a,a=b,b=t;
	}
	 printf("%c %c %c\n",a,b,c);//按照从小到大的顺序输出三个字母，用空格隔开
	}
	return 0;//程序正常结束
}