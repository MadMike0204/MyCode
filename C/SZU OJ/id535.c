#include<stdio.h>
#include<string.h>
static int NUM[9999];
void CombinationNumbers(const int Range,const int HowManyNumbersATime,const int AlreadySelected);
int main(){

    int Range,HowManyNumbersATime;
    scanf("%d %d",&Range,&HowManyNumbersATime);
    int NUM[9999];
    memset(NUM,0,sizeof(NUM));
    CombinationNumbers(Range,HowManyNumbersATime,0);
    return 0;
}

void CombinationNumbers(const int Range,const int HowManyNumbersATime,const int AlreadySelected)
{
    int i;
    if(HowManyNumbersATime > Range)
        return;
    if(HowManyNumbersATime == 0)
    {
        for(i=0;i<AlreadySelected;i++)
        {
            printf("%d",NUM[i]);
        }
        printf("\n");
    }
    else
    {
        NUM[AlreadySelected] = Range;
        CombinationNumbers(Range-1,HowManyNumbersATime-1,AlreadySelected+1);
        CombinationNumbers(Range-1,HowManyNumbersATime,AlreadySelected);
    }
}