#include <iostream>
#include <stdexcept>
using namespace std;

static int JOJO[10] = {8,6,444,342,798,125,66,-1,0,66};

void Selection_Sort(int* arr,int num);
void Bubble_Sort(int* arr,int num);
void Insection_Sort(int* arr,int num);

int* GenerateArr(int num)
{
    if(num <= 0)
    {
        throw std::invalid_argument("x must be greater than 0");
    }
    int* arr = new int[num];
    return arr;
}

int main(){

    for(int i=0;i<10;i++)
    {
        cout << JOJO[i] << " ";
    }
    cout << endl;

    Insection_Sort(JOJO,10);

    for(int i=0;i<10;i++)
    {
        cout << JOJO[i] << " ";
    }
    cout << endl;

    return 0;
}

void Selection_Sort(int* arr,int num)//选择排序，a为数组，num为待排序个数
{
    for(int i=0;i<num;i++)
    {
        int m = i;
        for(int j=i+1;j<num;j++)
        {
            if(arr[j] < arr[m])//升序/降序
            {
                m = j;
            }
        }
        std::swap(arr[i],arr[m]);
    }
}

void Bubble_Sort(int* arr,int num)
{
    bool flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i=0;i<num-1;i++)
        {
            if(arr[i] < arr[i+1])//升序/降序
            {
                flag = 1;
                std::swap(arr[i],arr[i+1]);
            }
        }
    }
}

void Insection_Sort(int* arr,int num)
{
    for(int i=0;i<num;i++)
    {
        int processing = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > processing)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = processing;
    }
}