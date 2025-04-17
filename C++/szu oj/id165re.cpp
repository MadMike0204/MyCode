#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;

class Customer
{
    private:
        static int TotalCustNum;
        static int Rent;
        static int Year;
        int CustID;
        char* CustName;
    public:
        Customer(const char* name)
        {
            CustName = new char[strlen(name)+1];
            strcpy(CustName,name);
            CustID = TotalCustNum + 1;
            TotalCustNum++;
        }
        ~Customer()
        {
            delete CustName;
        }
        static void changeYear(int r)
        {
            Year = r;
        }
        void Display()
        {
            cout << CustName << " "
                 << Year << std::setfill('0') << std::setw(4) << TotalCustNum << " "; 
            cout << TotalCustNum << " " << TotalCustNum * Rent << endl;
        }
};

int Customer::TotalCustNum = 0;
int Customer::Rent = 150; 
int Customer::Year = 2000;

int main(){

    vector<Customer*> customers;
    int t,year;
    char name[50];

    cin >> t;
    while(t > 0)
    {
        cin >> year;
        Customer::changeYear(year);
        while(1)
        {
            cin >> name;
            if(strcmp(name,"0") == 0)
            {
                break;
            }
            Customer* newnew = new Customer(name);
            newnew->Display();
            customers.push_back(newnew);
        }
        t--;
    }
    return 0;
}


