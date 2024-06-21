#include <iostream>
#include <cstring>
using namespace std;

class Cstr
{
    friend Cstr operator + (const Cstr &s1,const Cstr &s2);
    friend Cstr operator - (const Cstr &s1,const Cstr &s2);
    private:
        int length;
        char* p_content;
    public:

        Cstr()
        {
            length = 0;
            p_content = NULL;
        }
        Cstr(const Cstr &str)
        {
            p_content = new char[str.length + 1];
            strcpy(p_content,str.p_content);
            length = str.length;
        }   
        Cstr(int l,char* content)
        {
            length = l;
            p_content = new char[l+1];
            strcpy(p_content,content);
        }
        ~Cstr()
        {
            length = 0;
            delete p_content;
        }
        void print()
        {
            cout << "length=" << length << " " << p_content << endl;
        }
        Cstr operator = (const Cstr &x)
        {
            Cstr temp(x.length,x.p_content);
            return temp;
        }
        
};

int main(){

    int length;
    char* jojo;

    jojo = new char[100];

    cin >> jojo;
    length = strlen(jojo);
    Cstr jo(length,jojo);
    
    cin >> jojo;
    length = strlen(jojo);
    Cstr joo(length,jojo);

    return 0;
}

Cstr operator + (const Cstr &s1,const Cstr &s2)
{

}
Cstr operator - (const Cstr &s1,const Cstr &s2)
{

}