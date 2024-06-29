#include <iostream>
using namespace std;

class base
{
    protected:
        int a;
    public:
        base(int ia=0):
            a(ia){
                cout << "base: " << a << " constructed" << endl;
            }
};
class B1:virtual public base
{
    protected:
        int b1;
    public:
        B1(int ia,int ib1):
            base(ia),b1(ib1){
                cout << "B1: " << b1 << " constructed" << endl;
            }
};
class B2:virtual public base
{
    protected:
        int b2;
    public:
        B2(int ia,int ib2):
            base(ia),b2(ib2){
                cout << "B2: " << b2 << " constructed" << endl;
            }
};
class C:public B1,public B2
{
    protected:
        int c;
    public:
        C(int ia,int ib1,int ib2,int ic):
            base(ia),B1(ia,ib1),B2(ia,ib2),c(ic){
                cout << "C: " << c << " constructed" << endl;
            }
};
class D:public C
{
    protected:  
        int d;
    public:
        D(int ia,int ib1,int ib2,int ic,int id):
            C(ia,ib1,ib2,ic),d(id){
                cout << "D: " << d << " constructed" << endl;
            }
};
int main(){

    D jojo(1,2,3,4,5);

    return 0;
}