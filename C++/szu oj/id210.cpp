#include <iostream>
#include <iomanip>
using namespace std;
static char YorN[3] = {'Y','N'};

class CBook
{
    protected:
        bool isBroken;
        double amount;
        string name;
    public:
        CBook(bool isb,double a,string n):
            isBroken(isb),amount(a),name(n)
        {}
        virtual void printPrice(){};
};
class History:public CBook
{
    public:
        History(bool isb,double a,string n):
            CBook(isb,a,n)
        {
            amount = amount * 0.75 - 5; 
            if(isb == 1)
                amount *= 0.8;
            if(amount < 5 && a > 5)
                amount = 5;
            else if(amount < 0 || amount > a)
                amount = a;
        }
        virtual void printPrice()
        {
            cout << "History " << name << " " << fixed << setprecision(2) << amount << endl;
        }
};
class Science:public CBook
{
    public:
        Science(bool isb,double a,string n):
            CBook(isb,a,n)
        {
            amount = amount * 0.8 + 5; 
            if(isb == 1)
                amount *= 0.8;
            if(amount < 5 && a > 5)
                amount = 5;
            else if(amount < 0 || amount > a)
                amount = a;
        }
        virtual void printPrice()
        {
             cout << "Science " << name << " " << fixed << setprecision(2) << amount << endl;
        }
};
class Textbook:public CBook
{
    public:
        Textbook(bool isb,double a,string n):
            CBook(isb,a,n)
        {
            amount = amount * 0.5; 
            if(isb == 1)
                amount *= 0.8;
            if(amount < 5 && a > 5)
                amount = 5;
            else if(amount < 0 || amount > a)
                amount = a;
        }
        virtual void printPrice()
        {
            cout << "Textbook " << name << " " << fixed << setprecision(2) << amount << endl;
        }
};

int main(){

    string type,name;
    CBook* jojo = NULL;
    double price;
    char yon;
    bool yn = -1;
    int t;
    cin >> t;
    while(t > 0)
    {
        t--;
        cin >> type >> name >> price >> yon;
        if(yon == 'Y')
        {
            yn = 1;
        }
        else
        {
            yn = 0;
        }
        if(type[0] == 'H')
        {
            jojo = new History(yn,price,name);
        }
        else if(type[0] == 'S')
        {
            jojo = new Science(yn,price,name);
        }
        else if(type[0] == 'T')
        {
            jojo = new Textbook(yn,price,name);
        }
        jojo->printPrice();
    }

    return 0;
}