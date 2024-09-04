#include <iostream>
using namespace std;

struct SqList
{
    int length;
    int* arr;

    SqList(int l):length(l)
    {
        arr = new int[length];
        for(int i=0;i<length;i++)
        {
            cin >> arr[i];
        }
    }
    void Shift(bool direction,int time)
    {
        time %= length;
        if(!direction)
        {
            time = length - time;
        }
        int* temp = new int[length+time];
        
        //backup
        for(int i=0;i<length;i++)
        {
            temp[i+time] = arr[i];
        }
        for(int i=time;i<length;i++)
        {
            arr[i] = temp[i];
        }
        for(int i=0;i<time;i++)
        {
            arr[i] = temp[i+length];
        }

        delete[] temp;
    }
    void Print()
    {
        for(int i=0;i<length;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    int length;
    cin >> length;
    SqList Jo(length);
    Jo.Print();

    bool d;
    int step;

    cin >> d >> step;
    Jo.Shift(d,step);
    Jo.Print();

    cin >> d >> step;
    Jo.Shift(d,step);
    Jo.Print();

    return 0;
}