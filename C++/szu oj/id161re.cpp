#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Account {
private:
    string id;        
    string name;      
    double balance;  
    static double rate;  

public:
    Account(string id, string name, double balance);
    void deposit(double amount);      
    void withdraw(double amount);     
    void display() const;             
    static void setRate(double r);
    double getBalance() const;       

    friend void Update(Account& a);   
};

double Account::rate = 0.0; 

Account::Account(string id, string name, double balance) {
    this->id = id;
    this->name = name;
    this->balance = balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
}

void Account::display() const {
    cout << id << " " << name << " " << balance;
}

void Account::setRate(double r) {
    rate = r;
}

double Account::getBalance() const {
    return balance;
}

void Update(Account& a) {
    double interest = a.balance * Account::rate;
    a.balance += interest;
}

int main() {
    double rate;
    int n;
    
    cin >> rate;
    Account::setRate(rate);
    
    cin >> n;
    Account** accounts = new Account*[n];
    
    string id, name;
    double balance, depositAmount, withdrawAmount;
    
    for (int i = 0; i < n; i++) {
        cin >> id >> name >> balance >> depositAmount >> withdrawAmount;
        accounts[i] = new Account(id, name, balance);
        
        accounts[i]->deposit(depositAmount);
        double afterDeposit = accounts[i]->getBalance();
        
        Update(*accounts[i]);
        double afterInterest = accounts[i]->getBalance();
        
        accounts[i]->withdraw(withdrawAmount);
        double afterWithdraw = accounts[i]->getBalance();  

        cout << id << " " << name << " " << afterDeposit << " " << afterInterest << " " << afterWithdraw << endl;
    }
    
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += accounts[i]->getBalance();
    }
    cout << total << endl;
    
    for (int i = 0; i < n; i++) {
        delete accounts[i];
    }
    delete[] accounts;
    
    return 0;
}