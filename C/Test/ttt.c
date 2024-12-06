#include<stdio.h>
int isprime(int x){
	for(int i=2;i<x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
int main()
{
	int m,n;//输入2 3 输入3 9 
	int sum=0;
	scanf("%d%d",&m,&n);
	for(int i=m;i<=n;i++){
		if(isprime(i)){
			sum+=i;
		}
	}
	printf("%d",sum);//输出5 输出15
	return 0;
}