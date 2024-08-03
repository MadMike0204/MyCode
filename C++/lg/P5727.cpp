#include <iostream>
#include <cstring>
using namespace std;

void HailFunc(int N,int A[],int Serial);

int main(){

    int n,arr[234];
    cin >> n;
    memset(arr,0,sizeof(arr));
    HailFunc(n,arr,0);
    for(int i=233;i>=0;i--)
    {
        if(arr[i]>0)
        {
            if(i == 0)
            {
                cout << arr[i];
            }
            else
            {
                cout << arr[i] << " ";
            } 
        }
    }

    return 0;
}

void HailFunc(int N,int A[],int Serial)
{
    A[Serial] = N;
    if(N == 1)
    {
        return;
    }
    else if(N%2 == 0)
    {
        HailFunc(N/2,A,Serial+1);
    }
    else if(N%2 != 0)
    {
        HailFunc(N*3+1,A,Serial+1);
    }
}