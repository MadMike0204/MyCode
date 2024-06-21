#include<stdio.h>
#include<string.h>

int Comparision_2_Strings(const char *To_str1,const char*To_str2);

int main(){

    int t;
    scanf("%d",&t);
    getchar();
    char str1[15],str2[15];
    while(t>0)
    {
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
        scanf("%s%s",str1,str2);
        printf("%d\n",Comparision_2_Strings(str1,str2));
        t--;
    }

    return 0;
}

int Comparision_2_Strings(const char *To_str1,const char*To_str2)
{
    int len1 = 0,len2 = 0;
    int i;
    for(i=0;i<15;i++)
    {
        if(*(To_str1 + i) != 0)
        {
            len1++;
        }
        else if(*(To_str1 + i) == 0)
        {
            break;
        }
    }
    for(i=0;i<15;i++)
    {
        if(*(To_str2 + i) != 0)
        {
            len2++;
        }
        else if(*(To_str2 + i) == 0)
        {
            break;
        }
    }
    if(len1 > len2)
        return 1;
    else if(len2 > len1)
        return -1;
    int higher_str1 = 0,higher_str2 = 0;
    for(i=0;i<15;i++)
    {
        if(*(To_str1 + i) > *(To_str2 + i))
        {
            higher_str1++;
        }
        else if(*(To_str2 + i) > *(To_str1 + i))
        {
            higher_str2++;
        }
    }
    if(higher_str1 == higher_str2)
        return 0;
    else if(higher_str1 > higher_str2)
        return 1;
    else 
        return -1;
}