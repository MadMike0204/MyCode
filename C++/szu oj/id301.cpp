#include <iostream>
#include <cstring>
using namespace std;
class Cstr
{
    friend Cstr operator + (const Cstr &s1,const Cstr &s2);
    friend Cstr operator - (const Cstr &s1,const Cstr &s2);
    private:
        int length;
        char *p;
    public:
        Cstr()
        {
            length = 0;
            p = NULL;
        }
        Cstr(char *s)
        {
            length = strlen(s);
            p = new char[length+1];
            strcpy(p,s);
        }
        Cstr(const Cstr &s)
        {
            length = s.length;
            p = new char[length+1];
            strcpy(p,s.p);
        }
        ~Cstr()
        {
            delete[] p;
        }
        Cstr& operator = (const Cstr &s)
        {
            if(this != &s)
            {
                delete[] p;
                length = s.length;
                p = new char[length+1];
                strcpy(p,s.p);
            }
            return *this;
        }
        void show()
        {
            cout << "length=" << length << " " << p << endl;
        }
};
Cstr operator + (const Cstr &s1,const Cstr &s2)
{
    Cstr tp;
    tp.length = s1.length + s2.length;
    char* temp = new char[tp.length+1];
    tp.p = temp;

    for(int i=0;i<s1.length;i++)
    {
        temp[i] = s1.p[i];
    }
    for(int i=0;i<s2.length;i++)
    {
        temp[s1.length + i] = s2.p[i];
    }
    temp[tp.length] = 0;
    return tp;
}
Cstr operator - (const Cstr &s1,const Cstr &s2)
{
    Cstr tp;
    tp.length = s1.length - s2.length;
    char* temp = new char[tp.length+1];
    tp.p = temp;

    char* location;
    location = strstr(s1.p,s2.p); //
    
    for(int i=0;i<tp.length;i++)
    {
        if(&s1.p[i] < location)
            temp[i] = s1.p[i];
        else if(&s1.p[i] >= location)
            temp[i] = s1.p[s2.length+i];
    }
    temp[tp.length] = 0;
    return tp; 
}

int main(){

    char s1[40],s2[40];
    cin.getline(s1,39);
    cin.getline(s2,39);
    Cstr ss1(s1);
    Cstr ss2(s2);
    Cstr temp;
    temp = ss1 + ss2;
    temp.show();
    temp = temp - ss2;
    temp.show();

    return 0;
}