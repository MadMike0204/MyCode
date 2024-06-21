#include <iostream>
#include <cstring>
using namespace std;

void Change(char* original,char* num_str,char* result);

static int length;
static int numlength;

int main(){

    int t;
    cin >> t;
    string original;
    string num_str;
    char* to_original = &original[0];
    char* to_num_str = &num_str[0];
    char* to_result;
    while(t>0)
    {
        cin >> original;
        cin >> num_str;

        numlength = strlen(&num_str[0]);
        length = strlen(&original[0]);
        char result[length];
        to_result = &result[0];

        Change(to_original,to_num_str,to_result);
        cout << result << endl;
        
        t--;
    }

    return 0;
}

void Change(char* original,char* num_str,char* result)
{
    int location;
    int code = 0;
    for(int i=0;i<length;i++)
    {
        code = *(num_str + (i % numlength)) - '0';
        if(*(original+i) >='A' && *(original+i) <='Z')
        {
            location = (*(original+i) - 64 + code) % 26;
            *(result+i) = location + 64;
        }
        else if(*(original+i) >='a' && *(original+i) <='z')
        {
            location = (*(original+i) - 96 + code) % 26;
            *(result+i) = location + 96;
        }
    }
}