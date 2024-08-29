#include <iostream>
using namespace std;

int** Reform(int** const o_matrix,int n,int m,int p,int q)
{
    int idx = p * q;
    int** matrix = new int*[p];
    for(int i=0;i<p;i++)
    {
        matrix[i] = new int[q];
    }
    int arr[idx];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            arr[i*m+j] = o_matrix[i][j];
        }
    }
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            matrix[i][j] = arr[q*i+j];
            int k = matrix[i][j];
        }
    }
    return matrix;
}
int** Transpose(int** const o_matrix,int n,int m)
{
    int** matrix = new int*[m];
    for(int i=0;i<m;i++)
    {
        matrix[i] = new int[n];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j] = o_matrix[j][i];
        }
    }
    return matrix;
}

int Find(int** const matrix,int aim_n,int aim_m)
{
    return matrix[aim_n][aim_m];
}

int main(){

    int n,m,t,op,a,b;
    cin >> n >> m >> t;

    int** matrix = new int*[n];
    for(int i=0;i<n;i++)
    {
        matrix[i] = new int[m];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> matrix[i][j];
        }
    }
    while(t--)
    {
        cin >> op >> a >> b;
        if(op == 1)
        {
            matrix = Reform(matrix,n,m,a,b);
            n = a;
            m = b;
        }
        else if(op == 2)
        {
            matrix = Transpose(matrix,n,m);
            int temp = n;
            n = m;
            m = temp;
        }
        else if(op == 3)
        {
            cout << Find(matrix,a,b) << endl;
        }
    }

    return 0;
}