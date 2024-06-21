#include<stdio.h>
#include<string.h>

int LuckyWord(const char str[],int length);
int MaxNum(int N,const int arr[N]);
int MinNum(int N,const int arr[N]);
int isAprime(int x);

int main(){

    char M[99];
    int t,x;
    scanf("%d",&t);
    while(t > 0)
    {
        memset(M,0,sizeof(M));
        scanf("%s",M);
        x = LuckyWord(M,strlen(M));
        if(x)
            printf("Lucky Word\n%d\n",x);
        else 
            printf("No Answer\n0\n");
        t--;
    }

    return 0;
}


int isAprime(int x)
{
    if(x < 1 || x == 1)
        return 0;
    int i,j,isit = 1;
    for(i=2;i<=x/2;i++)
    {
        if(x%i == 0)
            isit = 0;
    }
    if(isit)
        return 1;
    else
        return 0;
}

int MaxNum(int N,const int arr[N])
{
    int i,max = -999,k;
    for(i=0;i<N;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            k = i;
        }
    }
    return max;
}

int MinNum(int N,const int arr[N])
{
    int i,min = 999,k;
    for(i=0;i<N;i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            k = i;
        }
    }
    return min;
}

int LuckyWord(const char str[],int length)
{
    int i,j,count = 0;
    char mem[99],word[99];
    int counter[26];
    memset(mem,0,sizeof(mem));
    memset(word,0,sizeof(word));
    memset(counter,0,sizeof(counter));
    for(i=0;i<length;i++)
    {
        word[i] = str[i];
    }
    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++)
        {
            if(word[i] == mem[j])
            {   
                counter[j]++;
                break;
            }
        }
        if(length == j)
        {
            mem[count] = word[i];
            count++;
        }
    }
    if(isAprime(MaxNum(count,counter)-MinNum(count,counter)))
    {
        return MaxNum(count,counter)-MinNum(count,counter);
    }
    else 
        return 0;

}