#include<iostream>
#include<stack>
using namespace std;
int main(){

    int t,l;
    char temp;
    cin >> t;
    string str,result;

    while(t--)
    {
        stack<char> s1,s2;
        cin >> str;
        l = str.length();
        for(int i=0;i<l;i++)
        {
            if(str[i] == '#')
            {
                if(s1.empty())
                    continue;
                s1.pop();
            }
            else
            {
                s1.push(str[i]);
            }
        }

        while(!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
        }

        if(s2.empty())
        {
            cout << "NULL" << endl;
            continue;
        }
        else
        {
            while(!s2.empty())
            {
                cout << s2.top();
                s2.pop();
            }
            cout << endl;
        }
    }

    return 0;
}