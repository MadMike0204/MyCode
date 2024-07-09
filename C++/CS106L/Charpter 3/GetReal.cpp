#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

double GetReal();

int main(){

    double JOJO = GetReal();
    cout << JOJO << endl;
    return 0;
}

double GetReal()
{
    while(1)
    {
        stringstream converter;
        string temp;
        getline(cin,temp);
        converter << temp;

        double result;
        if(converter >> result)
        {
            char remaining;
            if(converter >> remaining)
                cout << "Unexpected character:" << remaining << endl;
            else return result;
        }
        else
            cout << "Please enter an integer." << endl;
        
        cout << "Retry:";
    }
}