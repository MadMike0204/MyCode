#include <iostream>
using namespace std;

void F(int *arr,int n)
{
    int flag;
    for(int i=0;i<n;i++)
    {
        flag = 0;
        for(int j=0;j<i;j++)
        {
            if(arr[i] == arr[j] && arr[i] != -999)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            arr[i] = -999;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i] != -999)
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int n=7;
    int arr[n]={1,6,4,2,1,6,8};
    F(arr,n);

    return 0;
}