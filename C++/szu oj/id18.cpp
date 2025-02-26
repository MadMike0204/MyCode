#include<iostream>
#include<cstring>
using namespace std;
// index:从0开始记 index < length;
// 0 == error
int gsubstr(const string &str1,string &str2,int index){
    int length = str1.length();
    if(index >= length || index <= 0)
        return 0;
    str2 = str1.substr(index);
    return 1;
}

int main(){

    int n,idx;
    string s1,s2;
//
    cin >> n;
    cin.ignore();
//
    while(n--){
        //
        getline(cin,s1);
        cin >> idx;
        cin.ignore();
        //
        s2 = "";
        int rt = gsubstr(s1,s2,idx);
        if(rt && !s2.empty()){
            cout << s2 << endl;
        }
        else{
            cout << "IndexError" << endl;
        }
    }

    return 0;
}

/*
2
jojo3
3

*/