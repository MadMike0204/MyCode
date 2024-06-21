#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

static int length;
int isNumber(char* to_str);

int main(){

    int t;
    cin >> t;
    char str[99];
    char* to_str = &str[0];
    while(t>0)
    {
        cin >> str;
        cin.get();
        length = strlen(str);
        cout << isNumber(to_str) << endl;
        t--;
    }

    return 0;
}

int isNumber(char* to_str)
{
    bool flag = 1;
    int num = 0,bit;
    for(int i=0;i<length;i++)
    {
        if(*(to_str+i) >= '0' && *(to_str+i) <= '9')
        {   
        }
        else
        {
            flag = 0;
        }
    }
    if(flag == 0)
    {
        return -1;
    }
    else
    {
        for(int i=length-1;i>=0;i--)
        {
            bit = *(to_str+i) - '0';
            num += bit * (int)pow(10,length-1-i);
        }
        return num;
    }
}