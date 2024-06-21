#include <iostream>
using namespace std;
static char YorN[3] = {'Y','N'};

class CBook
{
    protected:
        bool isBroken;
        double amount;
        char* name;
    public:
        CBook(bool isb,double a,char* n):
            isBroken(isb),amount(a),name(n)
        {}
        virtual void printPrice(){};
};
class History:public CBook
{
    public:
        History(bool isb,double a,char* n):
            CBook(isb,a,n)
        {
            amount = amount * 0.75 - 5; 
        }
        virtual void printPrice()
        {
            cout << "History " << name << " " << amount << endl;
        }
};

int main(){

    char name[233] = "?";
    History jojo(1,28.8,name);
    jojo.printPrice();

    return 0;
}