#include <iostream>
using namespace std;

template<typename T>
T* Combine(T t1[],T t2[],int n)
{
    T* result = new T[2*n];
    for(int i=0;i<2*n;i++)
    {
        if(i < n)
        {
            result[i] = t2[i];
        }
        else
        {
            result[i] = t1[i-n];
        }
    }
    return result;
}

int main(){

    int t,num;
    char type;
    cin >> t;
    while(t--)
    {
        cin >> type >> num;
        if(type == 'I')
        {
            int arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            int arr2[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr2[i];
            }
            int* x = Combine<int>(arr,arr2,num);
            for(int i=0;i<2*num;i++)
            {
                cout << x[i];
            }
            cout << endl;
        }   
        else if(type == 'C')
        {    
            char arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            char arr2[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr2[i];
            }
            char* x = Combine<char>(arr,arr2,num);
            for(int i=0;i<2*num;i++)
            {
                cout << x[i];
            }
            cout << endl;
        } 
        else if(type == 'D')
        {
            double arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            double arr2[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr2[i];
            }
            double* x = Combine<double>(arr,arr2,num);
            for(int i=0;i<2*num;i++)
            {
                cout << x[i];
            }
            cout << endl;     
        }
    }
    return 0;
}
