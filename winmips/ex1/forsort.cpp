#include <iostream>
using namespace std;

const int length = 10;
int Array[length] = {1,7,2,4,7,1,5,2,4,5};

void swap(int& a,int& b) //
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Bubble_Sort()
{
    bool flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i=0;i<length-1;i++)
        {
            if(Array[i] > Array[i+1])//升序/降序
            {
                flag = 1;
                swap(Array[i],Array[i+1]);
            }
        }
    }
}

int main(){

    cout << "before sort the array is:" << endl;
    for(int i=0;i<length;i++)
    {
        cout << Array[i] << endl;
    }
    Bubble_Sort();

    cout << "after sort the array is:" << endl;
    for(int i=0;i<length;i++)
    {
        cout << Array[i] << endl;
    }

    return 0;
}