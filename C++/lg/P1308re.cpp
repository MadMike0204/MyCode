#include <iostream>
#include <cstring>
#include <istream>
#include <sstream>
#include <unordered_map>
using namespace std;

struct WordInfo{
    int index;
    int count = 0;
};

void ConvertCapital(string &context)
{
    for(int i=0;i<context.length();i++)
    {
        if(context[i]<=96 && context[i] != ' ')
            context[i] += 32;
    }
}

void ProcessContextToDiction(const string &context,std::unordered_map<string,int> &diction)
{
    int location = 0;
    stringstream JOJO;
    JOJO << context;
    string word;
    while(JOJO >> word)
    {
        if(!(diction.find(word) != diction.end()))
            diction[word] = 1;
        else
            diction[word]++;
        location++;
    }
}

int FindLocation(const string &word,const string &context)
{
    int start = 0;
    int wordlength = word.length();
    int length = context.length();
    int location;
    // for(int i=0;i<length;i++)
    // {
    //     location = context.find(word,i);
    //     if(location == 0 || context[location-1] == ' ')
    //     {
    //         if(context[location+word.length()] == ' ' || location+word.length() == length)
    //         {
    //             return location;
    //         }
    //     }
    // }
    while(start < length)
    {
        location = context.find(word,start);
        if(location == 0 || context[location-1] == ' ')
        {
            if(context[location+word.length()] == ' ' || location+word.length() == length)
            {
                return location;
            }
        }
        start += wordlength;
    }
    return -1;
}

int main(){

    std::unordered_map<string,int> diction;
    std::string context;
    std::string word;
    std::cin >> word;
    std::cin.ignore();
    std::getline(std::cin,context);
    ConvertCapital(word);
    ConvertCapital(context);
    ProcessContextToDiction(context,diction);
    int location = FindLocation(word,context);
    if(location != -1)
        cout << diction[word] << " " << location << endl;
    else   
        cout << "-1" << endl;

    return 0;
}