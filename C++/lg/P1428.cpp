#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    int num[n];
    for(int i=0;i<n;i++)
    {
        int N = 0;
        cin >> arr[i];
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i])
            {
                N++;
            }
        }
        num[i] = N;
    }
    for(int i=0;i<n;i++)
    {
        printf(i==0?"%d":" %d",num[i]);
    }
    return 0;
}