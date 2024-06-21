#include <iostream>
using namespace std;

class BaseAccount
{
    protected:
        string name;
        string id;
        int balance;
    public:
        BaseAccount(string n,string i,int b):
            name(n),id(i),balance(b){}
        void deposit(int sum)
        {
            balance += sum;
        }
        virtual void withdraw(int sum)
        {
            if(sum > balance)
            {
                cout << "insufficient" << endl;
                return;
            }
            balance -= sum;
        }
        virtual void display()
        {
            cout << name << " " << id << " " << "Balance:" << balance << endl;
            return;
        }
};
class BasePlus:public BaseAccount
{
    private:
        int limit;
        int limit_sum;
    public:
        BasePlus(string n,string i,int b):
            BaseAccount(n,i,b)
            {
                limit_sum = 0;
                limit = 5000;
            }
        virtual void withdraw(int sum)
        {
           if(sum > balance && sum <= balance+limit-limit_sum)
           {
                sum -= balance;
                balance = 0;
                limit_sum += sum;
           }
           else if(sum <= balance)
           {
                balance -= sum;
           }
           else if(sum > balance+limit-limit_sum)
           {
                cout << "insufficient" << endl;
           }
            return;
        }
        virtual void display()
        {
            cout << name << " " << id << " " << "Balance:" << balance << " limit:" << limit-limit_sum << endl;
            return;
        }
};
int main(){

    int t;
    cin >> t;
    string name,id;
    int limit,balance,a,b,c,d;
    BaseAccount *jojo,*m;
    while(t > 0)
    {
        cin >> name >> id >> balance;
        if(id[1] == 'A') //BaseAccount
        {
            m = new BaseAccount(name,id,balance);
        }
        else
        {
            m = new BasePlus(name,id,balance);
        }
        cin >> a >> b >> c >> d;
        jojo = m;
        jojo->deposit(a);
        jojo->withdraw(b);
        jojo->deposit(c);
        jojo->withdraw(d);
        
        jojo->display();

        t--;
    }


    return 0;
}