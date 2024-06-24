#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;

static int JOJO[10] = {8,6,444,342,798,125,66,1,0,66};

void Selection_Sort(int* arr,int num);
void Bubble_Sort(int* arr,int num);
void Insection_Sort(int* arr,int num);
void Counting_Sort(int* arr, int* result, int num);

int* GenerateArr(int num)
{
    if(num <= 0)
    {
        throw std::invalid_argument("x must be greater than 0");
    }
    int* arr = new int[num];
    return arr;
}
//测试用主函数
int main(){

    for(int i=0;i<10;i++)
    {
        cout << JOJO[i] << " ";
    }
    cout << endl;

    int* result = new int[10];
    Counting_Sort(JOJO,result,10);

    for(int i=0;i<10;i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
//排序函数实现
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
        while(j >= 0 && arr[j] > processing)//升序/降序
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = processing;
    }
}

void Counting_Sort(int* arr, int* result, int num) {
    if (num <= 0) return; // Check for empty array

    // Find the maximum and minimum values in the array
    int max = arr[0], min = arr[0];
    for (int i = 1; i < num; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Create and initialize the count array
    int range = max - min + 1;
    int* count = new int[range];
    memset(count, 0, range * sizeof(int));

    // Fill the count array
    for (int i = 0; i < num; i++) 
    {
        count[arr[i] - min]++;
    }

    // Accumulate the count array
    for (int i = 1; i < range; i++) 
    {
        count[i] += count[i - 1];
    }

    // Build the sorted result array
    for (int i = num - 1; i >= 0; i--) 
    {
        result[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Free the count array
    delete[] count;
}

// void Counting_Sort(int* arr,int* &result)
// {
//     int num = 10;
//     int max=-9999,min=0;
//     for(int i=0;i<num;i++)
//     {
//         if(arr[i] > max)
//         {
//             max = arr[i];
//         }
//         else if(arr[i] < min)
//         {
//             min = arr[i];
//         }
//     }

//     int count[max+1];
//     memset(count,0,sizeof(count));
//     for(int i=0;i<min;i++)
//     {
//         count[arr[i]]++;
//     }

//     for(int i=1;i<max+1;i++)
//     {
//         count[i] += count[i-1];
//     }
//     result =  new int[num];
//     for(int i=num;i>0;i--)
//     {
//         result[count[arr[i]]--] = arr[i];
//     }
// }