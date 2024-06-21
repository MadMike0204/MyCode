#include <iostream>
using namespace std;
int main()
{
    int t,swit=0;
    char str[6];
    cin >> t;
    while(t>0)
    {
        cin >> str;
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<5;j++)
            {
                str[j] += (i + swit);
            }
            cout << str << endl;
        }
        
        t--;
    }

    return 0;
}