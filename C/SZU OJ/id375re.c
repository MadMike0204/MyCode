#include<stdio.h>
#include<string.h>

void StaffingMagicSquare(const int N,int A[N][N]);
void PrintMagicSquare(const int N,const int A[N][N]);

int main(){

    int n;
    scanf("%d",&n);
    int MagicSquare[n][n];
    memset(MagicSquare,0,sizeof(MagicSquare));
    StaffingMagicSquare(n,MagicSquare);
    PrintMagicSquare(n,MagicSquare);

    return 0;
}

void StaffingMagicSquare(const int N,int A[N][N])
{
    A[0][N/2] = 1;
    int i,j,x = 0,y = N/2; // x行 y列
    for(i=2;i<=(N*N);i++)
    {
        if(x == 0 && y != N-1)
        {
            A[N-1][y+1] = i;
            x = N - 1;
            y = y + 1;
        }
        else if(x != 0 && y == N-1)
        {
            A[x-1][0] = i;
            x = x - 1;
            y = 0;
        }
        else if(x == 0 && y == N-1)
        {
            A[x+1][y] = i;
            x = x + 1;
            y = y;
        }
        else if(x != 0 && y != N-1 && A[x-1][y+1] == 0)
        {
            A[x-1][y+1] = i;
            x = x - 1;
            y = y + 1;
        }
        else
        {
            A[x+1][y] = i;
            x = x + 1;
            y = y;
        }
    }
    return;
}

void PrintMagicSquare(const int N,const int A[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(j==0? "%d":" %d",A[i][j]);
        }
        printf("\n");
    }
    return;
}