#include <iostream>
using namespace std;

class CAccount{

    private:
        long account = 0;
        char name[10];
        float balance = 0;
    public:
        void init_Account()
        {
            cin >> account >> name >> balance;
        }
        void deposit()
        {
            float input;
            cin >> input;
            if(input > 0)
            {
                balance += input;
                cout << "saving ok!" << endl;
            }
        }
        void withdraw()
        {
            float output;
            float temp = balance;
            cin >> output;
            if(output > 0)
            {
                temp -= output;
                if(temp < 0)
                {
                    cout << "sorry! over limit!" << endl;
                }
                else
                {
                    balance -= output;
                    cout << "withdraw ok!" << endl;
                }
            }
        }
        void check()
        {
            cout << name << "'s balance is "<< balance << endl;
        }
};


int main(){

    CAccount newnew;
    newnew.init_Account();
    newnew.check();
    newnew.deposit();
    newnew.check();
    newnew.withdraw();
    newnew.check();
    CAccount newnew2;
    newnew2.init_Account();
    newnew2.check();
    newnew2.deposit();
    newnew2.check();
    newnew2.withdraw();
    newnew2.check();

    return 0;
}