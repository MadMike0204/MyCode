#include<iostream>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;

class MyNumber
{
    double data;
    int IntegerPart;
    double DemicalPart;
    static const int BITS = 3;
    static const int PRECISION = 0.0001;
public:
    MyNumber(double data)
    {
        this->data = data;
        IntegerPart = floor(data);
        DemicalPart = data - IntegerPart;
    }

    void RescaleAndPrint(int scale=2)
    {
        stack<char> IntQ;
        queue<char> DemiQ;
        char temp;
        while(IntegerPart != 0)
        {
            temp = IntegerPart % scale;
            if(temp >= 0 && temp <= 9)
                temp += '0';
            else
                temp = temp + 'A' - 10;
            IntegerPart /= scale;
            IntQ.push(temp);
        }
        int bits = 0;
        while(bits < BITS)
        {
            DemicalPart *= scale;
            temp = floor(DemicalPart);
            if(temp >= 0 && temp <= 9)
                temp += '0';
            else
                temp = temp + 'A' - 10;
            DemiQ.push(temp);
            DemicalPart = DemicalPart - floor(DemicalPart);
            bits++;
        }
        while(!IntQ.empty())
        {
            cout << IntQ.top();
            IntQ.pop();
        }
        cout << ".";
        while(!DemiQ.empty())
        {
            cout << DemiQ.front();
            DemiQ.pop();
        }
        cout << endl;
    }
};

void test()
{
    MyNumber jojo(15.125);
    jojo.RescaleAndPrint(16);

}

int main(){

    int t,scale;
    double x;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> x >> scale;
        MyNumber jojo(x);
        jojo.RescaleAndPrint(scale);
    }

    return 0;
}