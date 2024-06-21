#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class myString
{
    friend int getNum(const myString &str);
    private:
        string origin;
    public:
        myString(const string &str_in)
        {
            origin = str_in;
        }
        myString()
        {
            origin = '0';
        }
        void SetOrigin(string &str)
        {
            origin = str;
        }
};
int getNum(const myString &str)
{
    int length = str.origin.length();
    char num_str[length];
    int num_length = 0;
    for(int i=0;i<length;i++)
    {
        if(str.origin[i] >= '0' && str.origin[i] <= '9')
        {   
            num_str[num_length] = str.origin[i];
            num_length++;
        }
    }
    int num = 0;
    for(int i=0;i<num_length;i++)
    {
        num += (num_str[i] - '0') * (int)pow(10,num_length-i-1);
    }
    return num;
}

int main(){

    int newnew;
    while(cin >> newnew)
    {
        myString sword[newnew];
        string str_in;

        for(int i=0;i<newnew;i++)
        {
            cin >> str_in;
            sword[i].SetOrigin(str_in);
        }

        int operation_times;
        cin >> operation_times;
        while(operation_times > 0)
        {
            string operation_code;
            short source_1,source_2;
            cin >> operation_code >> source_1 >> source_2;
            if(operation_code == "ADD")
            {
                cout << getNum(sword[source_1]) + getNum(sword[source_2]) << endl;
            }
            else if(operation_code == "MINUS")
            {
                cout << getNum(sword[source_1]) - getNum(sword[source_2]) << endl;
            }
            operation_times--;
        }
    }
    return 0;
}

