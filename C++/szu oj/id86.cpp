#include <iostream>
using namespace std;

class Account
{
    private:
        int number;
        int phone;
        int pw;
        int balance;
    public:
        Account()
        {
            number = 0;
            phone = 0;
            pw = 0;
            balance = 0;
        }
        void SetAccount(int a,int b,int c,int d)
        {
            number = a;
            phone = b;
            pw = c;
            balance = d;
        }
        bool isPasswordRight(int in_pw)
        {
            if(in_pw == pw)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        bool isBalanceEnough(int getout)
        {
            if(getout < balance)
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        }
        void getOutBalance(int getout)
        {
            balance -= getout;
        }
        int getBalance()
        {
            return balance;
        }
        int getPhone()
        {
            return phone;
        }
        int getNumber()
        {
            return number;
        }
        
};

int main(){

    int n;
    cin >> n;
    Account accounts[n];
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        accounts[i].SetAccount(a,b,c,d);
    }

    int k,phone,getout,in_pw,flag,target;
    cin >> k;
    for(int i=0;i<k;i++)
    {
        target = -1;
        cin >> phone >> in_pw >> getout;
        for(int j=0;j<n;j++)
        {
            if(phone == accounts[j].getPhone())
            {
                target = j;
                break;
            }
        }
        if(target == -1)
        {
            cout << "手机号不存在" << endl;
        }
        else
        {
            if(accounts[target].isPasswordRight(in_pw))
            {
                if(accounts[target].isBalanceEnough(getout))
                {
                    accounts[target].getOutBalance(getout);
                    cout << "卡号" << accounts[target].getNumber() << "--余额" << accounts[target].getBalance() << endl; 
                }
                else
                {
                    cout << "卡号" << accounts[target].getNumber() << "--余额不足" << endl;
                }
            }
        else
        {
            cout << "密码错误" << endl;
        }
        }
        
    }

    return 0;
}