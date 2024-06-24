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
        CVector(const CVector& V)
        {
            n = V.n;
            data = new int[n];
            for(int i=0;i<n;i++)
            {
                data[i] = V.data[i];
            }
        }
        int* GetArr()
        {
            return data;
        }
        int GetN()
        {
            return n;
        }
        void Display()
        {
            for(int i=0;i<n-1;i++)
            {
                cout << data[i] << " ";
            }
            cout << data[n-1] << endl;
        }
        friend CVector Add(const CVector V1,const CVector V2);
};
CVector Add(const CVector V1,const CVector V2)
{
    int n = V1.n;
    int* tem = new int[n];
    for(int i=0;i<n;i++)
    {
        tem[i] = V1.data[i] + V2.data[i];
    }
    CVector temp(n,tem);
    return temp;
}

int main(){

    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int* arr = new int[n];
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        CVector v1(n,arr);
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        CVector v2(n,arr);
        CVector v3 = Add(v1,v2);
        v1.Display();
        v2.Display();
        v3.Display();
    }

    return 0;
}