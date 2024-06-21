#include <iostream>
using namespace std;

void Function(int arr[])
{
    int i;
    for(i=0;i<5;i++)
    {
        arr[i] = i;
    }
}

int main(){

    static int arr[5];
    Function(arr);

    return 0;
}