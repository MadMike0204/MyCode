#include<iostream>
using namespace std;

void printArray(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf(i==0?"%d":" %d",arr[i]);
    }
    cout << endl;
}

void Insection_Sort(int* arr,int num)
{
    for(int i=1;i<num;i++)
    {
        int processing = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > processing)//升序/降序
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = processing;
        printArray(arr,num); // 每轮都打印
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
    Insection_Sort(arr,n);
    return 0;
}