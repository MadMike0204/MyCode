#include<iostream>
#include<cstring>
#include <iomanip>
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
        ~CVector()
        {
            if(data != NULL)
                delete data;
        }
        void Initial(int n,int* ar)
        {
            this->n = n;
            delete data;
            data = new int[n];
            for(int i=0;i<n;i++)
            {
                data[i] = ar[i];
            }
        }
        float Average()
        {
            float sum = 0;
            for(int i=0;i<n;i++)
            {
                sum += data[i];
            }
            return sum*1.0/n;
        }
        void Display()
        {
            for(int i=0;i<n;i++)
            {
                cout << data[i] << " ";
            }

        }
        int GetN()
        {
            return n;
        }
};

class CStudent
{
    private:
        string name;
        CVector score;
    public:
        CStudent(string name1,int n1,int* a1):
            name(name1)
        {
            score.Initial(n1,a1);
        }
        void Display()
        {
            cout << name << " ";
            score.Display();
            cout << fixed << setprecision(2) << score.Average() << endl;
        }
};

int main(){

    int n;
    char nm[30];
    while(scanf("%s %d",&nm,&n)!=EOF)
    {
        int* arr = new int[n];
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        int length = strlen(nm);
        string name;
        for(int i=0;i<length;i++)
        {
            name += nm[i];
        }
        CStudent jojo(name,n,arr);
        jojo.Display();
    }
    return 0;
}