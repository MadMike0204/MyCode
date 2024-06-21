#include <iostream>
using namespace std;

template<typename T>
void TSort(T *arr,int n)
{
    bool flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] > arr[i+1])
            {
                flag = 1;
                T temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

int main(){

    int t,num;
    char type;
    cin >> t;
    while (t--)
    {
        cin >> type >> num;
        if(type == 'I')
        {
            int arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            TSort(arr,num);
            for(int i=0;i<num;i++)
            {
                cout << arr[i] << " ";
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
            TSort(arr,num);
            for(int i=0;i<num;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        } 
        else if(type == 'S')
        {     
            string arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            TSort(arr,num);
            for(int i=0;i<num;i++)
            {
                cout << arr[i] << " ";
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
            TSort(arr,num);
            for(int i=0;i<num;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;      
        }
    }
    return 0;
}