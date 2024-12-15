#include<stdio.h>

#include<string.h>

int isP(char s[])
{
	int i = strlen(s);
	for(int j = 0;j < (i/2) ;j++)
	{
		int k = i - 1 - j;
		if(s[j] != s[k])
			return 1;
	}
	return 0;
}

int main(){

	int g;
	char str[100];
	scanf("%d",&g);
	
	getchar();

	while(g--)
	{
		fgets(str,sizeof(str),stdin);
		str[strcspn(str,"\n")] = '\0';
		if(isP(str) == 0){
			puts("Yes");
		}
		else 
			puts("No");
	}


	return 0;
}