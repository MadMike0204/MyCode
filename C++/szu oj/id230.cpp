#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>
using namespace std;
static float PRECISION = 0.001;
class CAccount
{
    protected:
        long account;
        char name[10];
        float balance;
    public:
        CAccount(const long &account_in,char* name_in,const float &balance_in):account(account_in),balance(balance_in)
        {
            strcpy(name,name_in);
        }
        void deposit(float in)
        {
            balance += in;
            cout << "saving ok!" << endl;
        }
        void withdraw(float out)
        {
            if(out < balance || fabs(out-balance) < PRECISION)
            {
                balance -= out;
                cout << "withdraw ok!" << endl;
            }
            else
            {
                cout << "sorry! over balance!" << endl;
            }
        }
        float getBalance()
        {
            return balance;
        }
};
class CCreditcard:public CAccount
{
    protected:
        float limit;
    public:
        CCreditcard(const long &account_in,char* name_in,const float &balance_in,float limit_in):
            CAccount(account_in,name_in,balance_in),limit(limit_in){}
        void withdraw(float out)
        {
            if(out < balance+limit || fabs(out-balance-limit) < PRECISION)
            {
                balance -= out;
                cout << "withdraw ok!" << endl;
            }
            else
            {
                cout << "sorry! over limit!" << endl;
            }
        }
};

int main(){

    char name[10];
    long account;
    float balance,out,in,limit;
    cin >> account >> name >> balance;
    CAccount sword(account,name,balance);
    cout << "balance is " << sword.getBalance() << endl;
    cin >> in;
    sword.deposit(in);
    cout << "balance is " << sword.getBalance() << endl;
    cin >> out;
    sword.withdraw(out);
    cout << "balance is " << sword.getBalance()<< endl;

    cin >> account >> name >> balance >> limit;
    CCreditcard jojo(account,name,balance,limit);
    cout << "balance is " << jojo.getBalance()<< endl;
    cin >> in;
    jojo.deposit(in);
    cout << "balance is " << jojo.getBalance()<< endl;
    cin >> out;
    jojo.CCreditcard::withdraw(out);
    cout << "balance is " << jojo.getBalance()<< endl;

    return 0;
}