#include <iostream>
#include <cstring>
using namespace std;

class Str{
        string str;
    public:
        Str(string s):str(s){}
        Str(const Str& obj){
            str = obj.str;
        }
        friend bool operator > (Str& a,Str& b){
            int l1 = a.str.length();
            int l2 = b.str.length();
            if(l1 > l2){
                return 1;
            }
            else{
                return 0;
            }
        }
        friend bool operator < (Str& a,Str& b){
            int l1 = a.str.length();
            int l2 = b.str.length();
            if(l1 < l2){
                return 1;
            }
            else{
                return 0;
            }
        }
        friend bool operator == (Str& a,Str& b){
            int l1 = a.str.length();
            int l2 = b.str.length();
            if(l1 == l2){
                return 1;
            }
            else{
                return 0;
            }
        }
        void show(){
            cout << str << endl;
        }
};


int main(){

    string a,b,c;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    Str aa(a);
    Str bb(b);
    Str cc(c);

    if(a>b){
        aa.show();
    }
    else{
        bb.show();
    }
    if(a<c){
        aa.show();
    }
    else{
        cc.show();
    }
    if(b==c){
        bb.show();
    }
    else{
        cc.show();
    }

    return 0;
}