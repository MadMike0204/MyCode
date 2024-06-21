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
            TotalCustNum = 0;
        }
        void Display()
        {
            cout << CustName << " " << std::setw(4)
                 << Year << " " << TotalCustNum << " " 
                 << TotalCustNum * Rent << endl;
        }
};

int Customer::TotalCustNum = 0;
int Customer::Rent = 150; 
int Customer::Year = 2000;

int main(){

    setlocale(LC_ALL, "zh_CN.UTF-8");
    char name[50];
    cin >> name;
    cout << name;

    return 0;
}