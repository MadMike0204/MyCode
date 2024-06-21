
#include<stdio.h>
#include<string.h>
#include<assert.h>
void my_strcpy(char* dest,char* src)
{
	assert(src != NULL);
	assert(dest != NULL);
	while (*dest++ = *src++)
	{
		;
	}
 
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
	char arr1[20],arr3[20];
	char arr2[] = "Hello";
    while(T>0)
    {
        scanf("%s%s",&arr1,&arr3);
        my_strcpy(arr1,arr2);
        printf("%s\n",arr1);
        T--;
    }
	return 0;
}