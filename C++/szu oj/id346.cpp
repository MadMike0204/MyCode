#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class ComplexNumber
{
    private:
        int real_component;
        int imaginary_componnet;
    public:
        ComplexNumber(int rc=0,int ic=0):
            real_component(rc),imaginary_componnet(ic){}
        void Display()
        {
            if(imaginary_componnet < 0)
            {
                cout << real_component << imaginary_componnet << endl;
            }
            else if(imaginary_componnet >= 0)
            {
                cout << real_component << "+" << imaginary_componnet << endl;
            }
        }
        void Reverse()
        {
            int temp = real_component;
            real_component = imaginary_componnet;
            imaginary_componnet = temp;
        }
};  

template<class T>
void reverse(T x)
{
    ostringstream stream;
    stream << x;
    string s = stream.str();
    int l = s.length();
    int flag = 0;
    int flag0 = 1;

    if(s[0] == '-')
    {
        flag = 1;
    }
    if(flag)
    {
        cout << "-";
        for(int i=l-1;i>=1;i--)
        {
            if(s[i] != '0')
                flag0 = 0;
            if(flag0 == 0)
                cout << s[i];
        }
    }

    else
    {
        for(int i=l-1;i>=0;i--)
        {
            if(s[i] != '0')
                flag0 = 0;
            if(flag0 == 0)
                cout << s[i];
        }
    }
    cout << endl;
}

template<>
void reverse(ComplexNumber x)
{
    x.Reverse();
    x.Display();
}

int main(){

    int t;
    char type;
    cin >> t;
    while(t--)
    {
        cin >> type;
        if(type == 'I')
        {
            int m;
            cin >> m;
            reverse<int>(m);
        }
        else if(type == 'D')
        {
            double m;
            cin >> m;
            reverse<double>(m);
        }
        else if(type == 'S')
        {
            string m;
            cin >> m;
            reverse<string>(m);
        }
        else if(type == 'C')
        {
            int a,b;
            cin >> a >> b;
            ComplexNumber m(a,b);
            reverse<ComplexNumber>(m);
        }
    }

    return 0;
}