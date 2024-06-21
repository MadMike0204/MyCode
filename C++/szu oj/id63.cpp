#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

static int SmallLetter[26];
static int CapitalLetter[26];
static int NUM[10];
static int length;

void GetSum(char* to_str);
void PrintResult();

int main(){

    int t;
    cin >> t;
    while(t > 0)
    {
        string str;
        cin >> str;
        cin.get();
        char* to_str = &str[0];
        length = strlen(to_str);
        GetSum(to_str);
        PrintResult();
        memset(NUM,0,sizeof(NUM));
        memset(SmallLetter,0,sizeof(SmallLetter));
        memset(CapitalLetter,0,sizeof(CapitalLetter));
        t--;
    }

    return 0;
}

void PrintResult()
{
    char a = '0';
    char b = 'a';
    char c = 'A';
    for(int i=0;i<10;i++)
    {
        if(NUM[i] > 0)
        {
            a = '0';
            a += i;
            cout << *dec << a << ":" << NUM[i] << " ";
        }
    }
    for(int i=0;i<26;i++)
    {
        if(CapitalLetter[i] > 0)
        {
            c = 'A';
            c += i;
            cout << c << ":" << CapitalLetter[i] << " ";
        }
    }
    for(int i=0;i<26;i++)
    {
        if(SmallLetter[i] > 0)
        {
            b = 'a';
            b += i;
            cout << b << ":" << SmallLetter[i] << " ";
        }
    }
    cout << endl;
}

void GetSum(char* to_str)
{
    int bit;
    char letter;
    for(int i=0;i<length;i++)
    {
        if(*(to_str+i) >= '0' && *(to_str+i)<= '9')
        {
           bit = *(to_str+i)-'0';
           NUM[bit]++;
        }
        else if(*(to_str+i) >= 'A' && *(to_str+i) <= 'Z')
        {
            bit = *(to_str+i) - 'A';
            CapitalLetter[bit]++;
        }
        else if(*(to_str+i) >= 'a' && *(to_str+i) <= 'z')
        {
            bit = *(to_str+i) - 'a';
            SmallLetter[bit]++;
        }
    }
}