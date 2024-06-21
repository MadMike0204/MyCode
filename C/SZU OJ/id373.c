#include<stdio.h>
#include<string.h>

static int arr[100][100];

void StaffingArr(const int n,const int m,int A[n][m]);
void AddingFlag(const int n,const int m,int A[n][m]);
void OutPutArr(const int n,const int m,int A[n][m]);

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF)
    {
        getchar();
        memset(arr,0,sizeof(arr));
        StaffingArr(n,m,arr);
        AddingFlag(n,m,arr);
        OutPutArr(n,m,arr);
    }

    return 0;
}

void StaffingArr(const int n,const int m,int A[n][m])
{
    int i,j,temp;
    char x[m+1];
    for(i=0;i<n;i++)
    {
        scanf("%s",x);
        for(j=0;j<m;j++)
        {
            if(x[j] == '*')
            {
                A[i][j] = -999;      
            }
            else if(x[j] == '?')
            {
                A[i][j] = 0;
            }
        }
    }
}

void AddingFlag(const int n,const int m,int A[n][m])
{
    int i,j,k,l;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(A[i][j] < 0)
            {
                for(k=i-1;k<=i+1;k++)
                {
                    if(k<0 || k>=n)
                    {
                        continue;
                    }
                    for(l=j-1;l<=j+1;l++)
                    {
                        if(l<0 || l>=m)
                        {
                            continue;
                        }
                        A[k][l]++;
                    }
                }
            }
        }
    }
}

void OutPutArr(const int n,const int m,int A[n][m])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(A[i][j]<0)
            {
                printf("*");
            }
            else
            {
                printf("%d",A[i][j]);
            }
        }
        printf("\n");
    }
}