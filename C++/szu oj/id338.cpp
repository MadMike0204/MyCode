#include <iostream>
#include <cmath>
using namespace std;

static double PRECISION = 0.001; 

template <class T>
int CFind(T arr[],int idx,T key)
{
    for(int i=0;i<idx;i++)
    {
        if(key == arr[i])
        {
            return i+1;
        }
    }
    return 0;
}
/*
template <class T>
T getArr(int idx,T label)
{
    T jojo[idx];
    for(int i=0;i<idx;i++)
    {
        cin >> jojo[i];
    }
}
*/

class Cdouble
{
    private:
        double value;
    public:
        Cdouble()
        {
            value = 0;
        }
        Cdouble(double x)
        {
            value = x;
        }
        bool operator == (Cdouble& x)
        {
            if(fabs(value - x.value) < PRECISION)
            {
                return 1;
            }
            return 0;
        }
        void set(double x)
        {
            value = x;
        }
        //friend istream & operator >> (istream & stream,
          //                          Cdouble &d);
};
/*
istream & operator >> (istream & stream,
                                    Cdouble &d)
{
    cin >> d.value;
    return stream;
}
*/

int main(){

    int t,num;
    char opcode;
    cin >> t;
    while(t--)
    {
        cin >> opcode >> num;
        if(opcode == 'I')
        {
            int arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            int aim;
            cin >> aim;
            cout << CFind(arr,num,aim) << endl;
        }
        else if(opcode == 'D')
        {
            Cdouble arr[num];
            double temp;
            for(int i=0;i<num;i++)
            {
                cin >> temp;
                arr[i].set(temp);
            }
            double a;
            cin >> a;
            Cdouble aim(a);
            cout << CFind(arr,num,aim) << endl;
        }
        else if(opcode == 'C')
        {
            char arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            char aim;
            cin >> aim;
            cout << CFind(arr,num,aim) << endl;
        }
        else if(opcode == 'S')
        {
            string arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            string aim;
            cin >> aim;
            cout << CFind(arr,num,aim) << endl;
        }
    }

    return 0;
}