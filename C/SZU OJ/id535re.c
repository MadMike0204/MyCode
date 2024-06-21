#include<stdio.h>
#include<string.h>

static int* To_Num[10] = {0};
static int Num[10] = {0,1,2,3,4,5,6,7,8,9};
static int flag_Num[10] = {0};

void GetNumberToPointer(const int Identifier,const int n);

void OutPutNumbers();
//输出组合数
void GetCombinationNumbers(const int n,const int r,const int AlreadySelected);
//获取组合数
int GetPointer(const int AlreadySelected,const int n);
//获取该次递归指针
void ResetP_To_Num(const int Location);
//重置本位递归及后位递归的指针为0
void MoveThePointer(const int Identifier);
//移动指针
int main(){

    int n,r;
    scanf("%d %d",&n,&r);
    GetCombinationNumbers(n,r,0);
    return 0;
}

void GetCombinationNumbers(const int n,const int r,const int AlreadySelected)
{
    if(AlreadySelected >= r)
    {
        return;
    }
    int i,j,Identifier,flag_reset;
    Identifier = GetPointer(AlreadySelected,n);
    while(To_Num[Identifier] != 0 && *To_Num[Identifier] >= r-AlreadySelected-1)
    {
        if(To_Num[Identifier] == 0)
        {
            GetNumberToPointer(Identifier,n);
        }
        GetCombinationNumbers(n,r,AlreadySelected+1);
        if((AlreadySelected+1) == r && To_Num[Identifier] != 0)
        {
            OutPutNumbers();
        }
        MoveThePointer(Identifier);
        if(*To_Num[Identifier] == r-AlreadySelected-1)
        {
            if(AlreadySelected == r-1)
            {
                ResetP_To_Num(Identifier);
            }
            
        }
    }
}


void ResetP_To_Num(const int Identifier)
{
    int i,Location = Identifier;
    for(i=Location;i>=1;i--)
    {
        if(To_Num[i] == 0)
            break;
        flag_Num[*To_Num[i]] = 0;
        To_Num[i] = 0;
    }
    return;
}

int GetPointer(const int AlreadySelected,const int n)
{
    int i,j,Identifier;
    for(i=9;i>=1;i--)
    {
        if(To_Num[i] == 0)
        {
            for(j=n;j>=1;j--)
            {
                if(flag_Num[j] == 0)
                {
                    To_Num[i] = &Num[j];
                    flag_Num[j] = 1;
                    Identifier = i;
                    return Identifier;
                }
            }
        }
    }
}

void GetNumberToPointer(const int Identifier,const int n)
{
    int j;
    for(j=n;j>=1;j--)
    {
        if(flag_Num[j] == 0)
        {
            To_Num[Identifier] = &Num[j];
            flag_Num[j] = 1;
            return;
        }
    }
}

void MoveThePointer(const int Identifier)
{
    if(To_Num[Identifier] == 0)
        return;
    int i,distance = 0;
    for(i=(*To_Num[Identifier]-1);i>=0;i--)
    {
        if(flag_Num[i] != 0)
        {
            distance++;
            continue;
        }
        else
        {
            distance++;
            flag_Num[i] = 1;
            flag_Num[*To_Num[Identifier]] = 0;
            To_Num[Identifier] -= distance;
            break;
        }
    }                                
}

void OutPutNumbers()
{
    int i;
    for(i=9;i>=1;i--)
    {
        if(To_Num[i] == 0)
        {
            break;
        }
        if(flag_Num[*To_Num[i]] == 1)
        {
            printf("%d",*To_Num[i]);
        }
    }
    printf("\n");
}
