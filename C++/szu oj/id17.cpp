#include<iostream>
using namespace std;

static int arr1[3][3],arr2[3][3];

void Rect(int A[][3],int B[][3]);

int main(){

    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin >> arr1[i][j];
        }
    }
    Rect(arr1,arr2);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           printf("%d ",arr2[i][j]);
        }
        cout << endl;
    }

    return 0;
}

void Rect(int A[][3],int B[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            B[i][j] = A[j][i];
        }
    }
}