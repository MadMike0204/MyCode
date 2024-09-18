#include<iostream>
#include<stack>
using namespace std;
void test()
{
    stack<int> r;
    for(int i=0;i<5;i++)
    {
        r.push(i);
    }
    for(int i=0;i<6;i++)
    {
        r.pop();
    }
}
int main(){

    int t,l;
    char ch;
    string str;
    cin >> t;
    while(t--)
    {
        cin >> str;
        l = str.length();
        stack<char> reversed;
        for(int i=0;i<l;i++)
        {
            reversed.push(str[i]);
        }
        while(!reversed.empty())
        {
            ch = reversed.top();
            reversed.pop();
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}