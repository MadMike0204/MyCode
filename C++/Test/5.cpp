#include <iostream>
using namespace std;

static double rt;

double& swap(int &m,int &n)
{
    rt = m + n;
    cout << "传入的引用m的地址" << &m << endl << "传入的引用m的地址" << &n << endl;
    return rt;
}

int main(){

    int arr[233] = {0};
    int (&r1_arr)[233] = arr;
    int* p = arr;
    int* &r2_arr = p;
    int a = 99,b = 23;
    cout << &r1_arr << "\n" << *&r2_arr << endl;
    int i;
    for(i=0;i<233;i++)
    {
        r1_arr[i] = i;
    }
    for(i=0;i<233;i++)
    {
        cout << *(r2_arr + i) << " ";
    }

    return 0;
}