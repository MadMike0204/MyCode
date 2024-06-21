#include<stdio.h>
#include<string.h>

int Substring(char str1[],char str2[],int index)
{
    int len = strlen(str1);
    if(index < 0)
        return 0;
    else if(str1[index] == 0)
        return 0;
    else if(index >= len)
        return 0;
    int i;
    for(i=0;i<99;i++)
    {
        if(str1[i] == 0)
            break;
        str2[i] = str1[index+i];
    }
    return 1;
}

int main(){

    char str1[99],str2[99];
    int t,index,i,temp,n;
    scanf("%d",&t);
    getchar();
    while(t>0)
    {
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
        n=0;
        for(i=0;;i++)
        {
            temp = getchar();
            if(temp == '\n')
            {
                break;
            }
            else
            {
                str1[n] = temp;
                n++;
            }
        }
        scanf("%d",&index);
        getchar();
        if(Substring(str1,str2,index))
        {
            printf("%s\n",str2);
        }
        else
        {
            printf("IndexError\n");
        }
        t--;
    }

    return 0;
}