#include<iostream>
using namespace std;

class CVector
{
    private:
        int *data;
        int n;
    public:
        CVector(int nn=5,int* arr = NULL):
            n(nn)
        {
            if(arr == NULL)
            {
                data = new int[5];
                for(int i=0;i<5;i++)
                {
                    data[i] = i;
                }
            }
            else 
            {
                data = new int[n];
                for(int i=0;i<n;i++)
                {
                    data[i] = arr[i];
                }
            }
        }
        void Display()
        {
            for(int i=0;i<n-1;i++)
            {
                cout << data[i] << " ";
            }
            cout << data[n-1] << endl;

        }
};


int main(){

    CVector jojo;
    jojo.Display();
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
    {   
        cin >> arr[i];
    }
    CVector jostar(n,arr);
    jostar.Display();

    return 0;
}