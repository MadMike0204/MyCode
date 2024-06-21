#include <iostream>
using namespace std;

class CComplex
{
    private:
        int a;
        int b;
    public:
        CComplex(double r = 0.0,double i = 0.0)
        {
            a = r;
            b = i;
        }
        CComplex& operator += (const CComplex &Cc)
        {
            a += Cc.a;
            b += Cc.b;
            return *this;
        }
        void print()
        {
            cout << "x = " << a << " + " << b << "i"  << endl;
        }
};

int main(){

    CComplex st1(2,3);
    CComplex st2(4,4);
    st1 += st2;
    st1.print();

    return 0;
}