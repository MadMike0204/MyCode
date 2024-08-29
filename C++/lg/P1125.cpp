#include <iostream>
#include <cmath>
using namespace std;

int FindGapBetweenMaxAndMin(string s)
{
    int alpha_map[26] = {0};
    for(int i=0;i<s.length();i++)
    {
        alpha_map[s[i]-97]++;
    }
    int min = 999;
    int max = -1;
    for(int i=0;i<26;i++)
    {
        if(alpha_map[i]>max)
            max = alpha_map[i];
        if(alpha_map[i]<min && alpha_map[i]!=0)
            min = alpha_map[i];
    }
    return max-min;
}

bool isAprime(int x)
{
    if(x <= 1)
        return 0;
    bool flag = 1;
    for(int i=2;i<sqrt(x);i++)
    {
        if(x%i == 0)
        {
            flag = 0;
            return flag;
        }
    }
    return flag;
}

int main(){ 

    string str;
    cin >> str;
    isAprime(FindGapBetweenMaxAndMin(str));
    if(isAprime(FindGapBetweenMaxAndMin(str)))
        cout << "Lucky Word" << endl << FindGapBetweenMaxAndMin(str) << endl;
    else
        cout << "No Answer" << endl << '0' << endl;
    return 0;
}