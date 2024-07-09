#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int GetInteger();
bool GetBoolean();

int main(){

    int JOJO = GetBoolean();
    cout << JOJO << endl;
    return 0;
}

bool GetBoolean()
{
    while(1)
    {
        stringstream converter;
        string temp;
        getline(cin,temp);
        converter << temp;

        string result;
        if(converter >> result)
        {
            if(result == "true")
                return 1;
            else if(result == "false")
                return 0;
            else
            cout << "Please enter \"true\" or \"false\"" << endl;
        }
    }
    
}
