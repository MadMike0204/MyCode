#include<stdio.h>
#include<string.h>

int isNumber(char* To_P_Arr);

int main(){

    char Possible_Arr[99];
    int t,ggNOre,isHaveZeroAhead;
    scanf("%d",&t);
    getchar();
    while(t>0)
    {
        isHaveZeroAhead = 1;
        memset(Possible_Arr,0,sizeof(Possible_Arr));
        scanf("%s",Possible_Arr);
        ggNOre = isNumber(Possible_Arr);
        if(ggNOre == -1)
        {
            printf("-1\n");
        }
        else
        {
            int i;
            for(i=0;i<99;i++)
            {
                if(Possible_Arr[i] == 0)
                    break;
                else if(Possible_Arr[i] != '0')
                {
                    isHaveZeroAhead = 0;
                    printf("%c",Possible_Arr[i]);
                }
                else if(Possible_Arr[i] == '0' && isHaveZeroAhead == 1)
                {
                    continue;
                }
                else if(Possible_Arr[i] == '0' && isHaveZeroAhead == 0)
                {
                    printf("0");
                }
            }
            printf("\n");
        }

        t--;

    }

    return 0;
}

int isNumber(char* To_P_Arr)
{
    int i,flag = 1;
    for(i=0;i<99;i++)
    {
        if(*(To_P_Arr + i) == 0)
            break;
        if(*(To_P_Arr + i) < '0' || *(To_P_Arr + i) > '9')
        {
            flag = 0;
        }
    }
    if(flag)
        return 1;
    else 
        return -1;
}