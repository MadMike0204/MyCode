#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if(num <= 1)
        return 0;
    bool flag = 1;
    for(int i=2;i<=(int)sqrt(num);i++)
    {
        if(num % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

void PrimeNumberGriddle(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        if(!isPrime(arr[i]))
        {
            arr[i] = 0;
        }
    }
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    PrimeNumberGriddle(arr,n);
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]!=0)
            cout << arr[i] << " ";
    }
    if(arr[n-1] != 0)
        cout << arr[n-1] << endl;

    return 0;
}