#include <iostream>
#include <string>
#include <iomanip>
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

int main(){

    int a,b;
    cin >> a >> b;
    ComplexNumber m(a,b);
    m.Display();
    m.Reverse();
    m.Display();


    return 0;
}