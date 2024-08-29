#include <iostream>
#include <cstring>
#include <istream>
#include <sstream>
#include <unordered_map>
#include <map>
using namespace std;

void ProcessContextToDiction(string context,std::map<string,int> &diction)
{
    int location = 0;
    stringstream JOJO;
    JOJO << context;
    string word;
    while(JOJO >> word)
    {
        if(!(diction.find(word) != diction.end()))
        {
            diction[word] = location;
        }
        location++;
    }
}

int main(){

    std::map<string,int> diction;
    std::string context;
    std::string word;
    std::cin >> word;
    std::cin.ignore();
    std::getline(std::cin,context);

    ProcessContextToDiction(context,diction);

    for(std::map<string,int>::iterator it = diction.begin();it != diction.end();it++)
    {
        std::cout << it->first << "=>" << it->second << std::endl;
    }

    return 0;
}