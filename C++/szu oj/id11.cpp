#include <iostream>
#include <string>
#include <cmath>
using namespace std;

static int bits;

long change(char s[]);

int main(){

    int t;
    char arrH[12];
    cin >> t;
    cin.get();
    while(t > 0)
    {
        cin.getline(arrH,12);
        int i;
        for(i=0;i<12;i++)
        {
            if(arrH[i] == 0)
            {
                break;
            }
        }
        bits = i;
        cout << change(arrH) << endl;
        t--;
    }

    return 0;
}

long change(char s[])
{
    long X = 0;
    int i,location;
    for(i=0;i<bits;i++)
    {
        if(s[i] >= '0' && s[i] <='9')
        {
            location = s[i] - '0';
            X += location * (long)pow(16,bits-i-1);
        }
        else if(s[i] >= 'A' && s[i] <= 'F')
        {
            location = s[i] - 'A' + 10;
            X += location * (long)pow(16,bits-i-1);
        }
    }
    return X;
}