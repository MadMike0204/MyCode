#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void OpenFile(ifstream &x)
{
    string filename;
    
    while(1)
    {
        cout << "Please enter a name of a existant file:";
        cin >> filename;
        x.close();
        x.open(filename);
        if(!x.is_open())
        {
            cerr << "Error,non-existant file. Please enter a name of an existant file";
            continue;
        }
        return;
    }
}

int main(){

    ifstream myFile;
    OpenFile(myFile);
    string content;
    
    while(getline(myFile,content))
    {
        cout << content << endl;
    }

    return 0;
}