#include<string>
#include<iostream>
using namespace std;
class Account{
    public:
        Account(string accno,string name,float balance);
        ~Account();
        void Deposit(float amount);
        float GetBalance();
        void Show();
        static int GetCount();
        static float GetInterestRate();
    private:
        static int count;
        static float InterestRate();
        string _accno,_accname;
        float _balance;
};
int main(){

    float rate;
    cin >> rate;
    int n;
    string accno,name;
    float balance,deposit,withdraw;
    while(n--){
        cin >> accno >> name >> balance >> deposit >> withdraw;
        // 输出信息
    }

    return 0;
}