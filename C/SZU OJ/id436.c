#include<stdio.h>
#include<string.h>

int main()
{
	int t;
	scanf("%d",&t);
    getchar();
	while (t--)
	{
		char str1[20], str2[20], str3[20];
		scanf("%s %s", str1,20, str2,20);
        getchar();
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int i, j;
		for (i = 0; i < 3; i++)
		{
			*(str3 + i) = *(str1 + i);
		}
		*(str3 + i) = '\0';
		int len3 = strlen(str3);
		for (j = len2-3, i = len3; j <len2; j++, i++)
		{
			*(str3 + i) = *(str2 + j);
		}
		*(str3 + i) = '\0';
		printf("%s\n", str3);
	}
	return 0;
}