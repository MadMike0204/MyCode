#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct PP
{
    string name;
    string terminal;
    string oprt;
    string Issuer;
    string validity;
    string cardnumber;
    string time;
    double costs;
};

PP NewPos(int n);
void Printl(PP &pos);

int main(){

    int t;
    cin >> t;
    PP newnew;
    while(t>0)
    {  
        newnew = NewPos(1);
        Printl(newnew);
        t--;
        if(t != 0)
        {
            cout << endl;
        }
    }


    return 0;
}

PP NewPos(int n)
{
    PP pos;
    cin >> pos.name >> pos.terminal >> pos.oprt >> pos.Issuer >> pos.validity
        >> pos.cardnumber >> pos.time >> pos.costs;
    return pos;
}

void Printl(PP &pos)
{
    cout << "Name: " << pos.name << endl
         << "Terminal: " << pos.terminal << " operator: " << pos.oprt << endl
         << "Card Issuers: " << pos.Issuer << " Validity: " << pos.validity << endl
         << "Card Number: " << pos.cardnumber[0] 
         << pos.cardnumber[1] << pos.cardnumber[2] 
         << pos.cardnumber[3] << "********"
         << pos.cardnumber[12] << pos.cardnumber[13] 
         << pos.cardnumber[14] << pos.cardnumber[15] << endl
         << "Traded: " << pos.time << endl
         << "Costs: $";
    cout << fixed << setprecision(2) << pos.costs << endl;
}