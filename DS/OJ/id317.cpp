#include<iostream>
using namespace std;

void Insection_Sort(int* arr,int num)
{
    for(int i=0;i<num;i++)
    {
        int processing = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > processing)//升序/降序
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = processing;
    }
}

void ShellSort(int *arr,int n)
{
    int gap = n;
    int tempArr[n];
    while(gap/n)
    {
        
    }
}

int main(){



    return 0;
}