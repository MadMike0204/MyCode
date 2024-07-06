#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int GetInteger();

int main(){

    int JOJO = GetInteger();
    cout << JOJO << endl;
    return 0;
}

int GetInteger()
{
    while(1)
    {
        stringstream converter;
        string temp;
        getline(cin,temp);
        converter << temp;

        int result;
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