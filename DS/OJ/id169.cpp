#include<iostream>
#include<string>
using namespace std;

void GetNext(string p,int next[])
{
    int i,j;
    i = 0;
    j = -1;
    // next数组 第一个默认为-1 下标从0开始
    next[i] = j;
    while(i < p.length() - 1)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

string matched_Prefix_Postfix(string str)
{
    string result = "";
    str += '-';
    int length = str.length();
    int* next = new int[length];
    GetNext(str,next);

    int max = -1;

    max = next[length-1];
    if(max <= 0)
    {
        result = "empty";
        return result;
    }
    
    for(int i=0;i<max;i++)
    {
        result += str[i];
    }
    return result;

}

int main(){

    int t;
    cin >> t;
    string str;
    string result;
    while(t--)
    {
        cin >> str;
        result = matched_Prefix_Postfix(str);
        cout << result << endl;
    }

    return 0;
}