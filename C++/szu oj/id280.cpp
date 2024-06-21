#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

class TripVipCard
{
    protected:
        int id;
        int points;
    public:
        TripVipCard(int id_in,int points_in = 0):
            id(id_in),points(points_in){}
        void add(int amount)
        {
            points += amount;
        }
        void refund(int amount)
        {
            points -= amount;
        }
};
class CreditCard
{
    protected:
        int id;
        string name;
        int limit;
        float bill;
        int points;
    public:
        CreditCard(int id_in,int limit_in,const string &name_in,int points_in = 0,float bill_in = 0):
            id(id_in),points(points_in),limit(limit_in),bill(bill_in),name(name_in){}
        void add(float amount)
        {
            if(bill + amount > limit)
            {
                return;
            }
            else
            {
                bill += amount;
                points += (int)amount;
            }
        }
        void refund(float amount)
        {
            bill -= amount;
            points -= (int)amount;
        }
};
class TripCreditCard:public TripVipCard,public CreditCard
{
    public:
        TripCreditCard(int id1_in,int id2_in,int limit_in,const string &name_in):
            TripVipCard(id1_in),CreditCard(id2_in,limit_in,name_in,0,0){}
        void add(float amount)
        {
            TripVipCard::add((int)amount);
            CreditCard::add(amount);
        }
        void exchange(int amount)
        {
            TripVipCard::points += amount / 2;
            CreditCard::points -= amount;
        }
        void display()
        {
            cout << TripVipCard::id << " " << TripVipCard::points << endl
                 << CreditCard::id << " " << CreditCard::name << " " 
                 << CreditCard::bill << " " << CreditCard::points << endl;
        }
};

int main(){

    int t,id1,id2,limit,amount;
    string name;
    float bill,refund;
    cin >> id1 >> id2 >> name >>limit;
    TripCreditCard jojo(id1,id2,limit,name);
    char operation;
    cin >> t;
    while(t > 0)
    {
        cin >> operation;
        switch (operation)
        {
            case 'o':
                cin >> bill;
                jojo.add(bill);
                break;
            case 'c':
                cin >> bill;
                jojo.CreditCard::add(bill);
                break;
            case 'q':
                cin >> refund;
                jojo.CreditCard::refund(refund);
                break;
            case 't':
                cin >> amount;
                jojo.exchange(amount);
        }
        t--;
    }
    jojo.display();
    return 0;
}