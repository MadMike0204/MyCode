#include<stdio.h>
#include<string.h>
int main(){

    char str1[21],str2[21];
    scanf("%s%s",&str1,&str2);
    int len1,len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    char* To_str2 = &str2[0];
    int i,count = 0;
    for(i=0;i<len1;i++)
    {
        if(*To_str2 == str1[i])
        {
            To_str2++;
        }
        else
        {
            To_str2 = &str2[0];
        }
        if(To_str2 == &str2[len2])
        {
            To_str2 = &str2[0];
            count++;
        }
    }
    printf("%d",count);
    return 0;
}