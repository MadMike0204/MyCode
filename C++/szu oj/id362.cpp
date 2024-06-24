#include<iostream>
#include<vector>
using namespace std;

class CVector
{
    private:
        int *data;
        int n;
        static int sum;
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
                    sum += arr[i];
                }
            }
        }
        ~CVector()
        {
            for(int i=0;i<n;i++)
            {
                sum -= data[i];
            }
            n = 0;
            if(data != NULL)
            {
                delete data;
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
        static int getSum()
        {
            return sum;
        }
};

int CVector::sum = 0;

int main(){

    int t,num,N;
    cin >> t;
    while(t--)
    {
        vector<CVector*> Vs;
        CVector* jojo = NULL;
        cin >> num;
        while(num--)
        {
            cin >> N;
            int* arr = new int[N];
            for(int i=0;i<N;i++)
            {
                cin >> arr[i];
            }
            jojo = new CVector(N,arr);
            Vs.push_back(jojo);
            delete[] arr;
        }
        for(CVector* v:Vs)
        {
            v->Display();
        }
        cout << CVector::getSum() << endl;
        for(CVector* v:Vs)
        {
            delete v;
        }   
    }

    return 0;
}