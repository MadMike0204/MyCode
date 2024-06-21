#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class CPoint
{
    private:
        double x,y;
    public:
        CPoint(double a=0,double b=0):
            x(a),y(b){}
        double GetDistance()
        {
            return sqrt(x*x + y*y);
        }
        friend ostream& operator<< (ostream &os,const CPoint& point);
        friend istream& operator>> (istream &is,CPoint& point);
};

ostream& operator<< (ostream &os,const CPoint& point)
{
    os  << fixed << setprecision(1) << "(" << point.x << ", " << point.y << ")";
    return os;
}

istream& operator>> (istream &is,CPoint& point)
{
    is >> point.x >> point.y;
    return is;
}

template<class T>
void Csort(T(&arr)[],int num)
{
    for(int i=0;i<num-1;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(arr[i] > arr[j])
            {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
template<>
void Csort(CPoint(&arr)[],int num)
{
    for(int i=0;i<num-1;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(arr[i].GetDistance() > arr[j].GetDistance())
            {
                CPoint temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
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
            Csort<int>(arr,num);
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
            Csort<double>(arr,num);
            for(int i=0;i<num;i++)
            {
                cout << fixed << setprecision(1) << arr[i] << " ";
            }
            cout << endl;
        }
        else if(type == 'P')
        {
            CPoint arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            Csort<CPoint>(arr,num);
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
            Csort<string>(arr,num);
            for(int i=0;i<num;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}