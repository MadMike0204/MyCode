#include<iostream>
#include<cstring>
using namespace std;

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

int main(){

    int N,result = 0;
    cin >> N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    Selection_Sort(arr,N);
    
    bool flag;
    for(int i=N-1;i>=2;i--)
    {
        flag = 0;
        for(int j=i-1;j>=1;j--)
        {
            for(int k=j-1;k>=0;k--)
            {
                if(arr[i] == arr[j] + arr[k])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
            {
                result++;
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}