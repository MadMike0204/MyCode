#include <iostream>
using namespace std;

class Fraction
{
    private:
        int numerator,denominator;
//        int common_divisor();
//        void contracted();
    public:
        Fraction(int x,int y)
        {
            numerator = x;
            denominator = y;
        }
        Fraction(Fraction &x)
        {
            this->numerator = x.numerator;
            this->denominator = x.denominator; 
        }
        Fraction operator+(Fraction x)
        {
            Fraction t(0,0);
            t.denominator = this->denominator * x.denominator;
            t.numerator = (this->numerator * x.denominator + x.numerator * this->denominator);
            return t;
        }
        Fraction operator-(Fraction x)
        {
            Fraction t(0,0);
            t.denominator = this->denominator * x.denominator;
            t.numerator = this->numerator * x.denominator - x.numerator * this->denominator;
            return t;
        }
        Fraction operator*(Fraction x)
        {
            Fraction t(0,0);
            t.denominator = this->denominator * x.denominator;
            t.numerator = this->numerator * x.numerator;
            return t;
        }
        Fraction operator/(Fraction x)
        {
            Fraction t(0,0);
            t.denominator = this->denominator * x.numerator;
            t.numerator =  this->numerator * x.denominator;
            return t;
        }
        void Set(int x,int y)
        {
            numerator = x;
            denominator = y;
        }
        void disp()
        {
            cout << "fraction=" << numerator << "/" << denominator << endl;
        }
};

int main(){

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Fraction F1(x1,y1);
    Fraction F2(x2,y2);

    F1 = F1 + F2;
    F1.disp();
    F1.Set(x1,y1);

    F1 = F1 - F2;
    F1.disp();
    F1.Set(x1,y1);

    F1 = F1 * F2;
    F1.disp();
    F1.Set(x1,y1);

    F1 = F1 / F2;
    F1.disp();

    return 0;
}