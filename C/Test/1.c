#include <stdio.h>
int Substring(char str1[],char str2[],int index,int k)//k是长度 
{
	if(index>k)
	{
		return 0;
	}
	for(int i=0;str1[index-1+i]!='\0';i++)
	{
		str2[i]=str1[index-1+i];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
    // getchar();

	while(n--)
	{
		char str1[40],str2[40];
		int index;

		scanf("%s",str1);


		int k;
		for(k=0;;k++)
		{
			if(str1[k]=='\n')
			break;
		}
		scanf("%d",&index);

		int c=Substring(str1,str2,index,k);
		if(c==0)
		printf("IndexError\n");
		else
		printf("%s\n",str2);
		
	}
	return 0;
}