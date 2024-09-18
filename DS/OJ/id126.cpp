#include<iostream>
#include<stack>
using namespace std;

char Pair(char ch)
{
    if(ch == '{')
        return '}';
    if(ch == '[')
        return ']';
    if(ch == '(')
        return ')';
    return 0;
}

int main(){

    stack<char> s;
    string str;
    int t,l;
    cin >> t;
    while(t--)
    {
        char expected;
        bool flag = 0;
        cin >> str;
        l = str.length();
        for(int i=0;i<l;i++)
        {
            switch (str[i])
            {
                case ')':
                case '}':
                case ']':
                    if(expected == str[i])
                        s.pop();
                    else
                        flag = 1;
                    break;
                case '(':
                case '[':
                case '{':
                        expected = Pair(str[i]);
                        s.push(str[i]);
                        break;
                default:
                    break;
            } 
            if(flag)
            {
                break;
            }
            if(!s.empty())
                expected = Pair(s.top());
        }
        if(!flag && s.empty())
        {
            cout << "ok" << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    return 0;
}