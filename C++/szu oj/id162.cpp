#include<iostream>

class complex{
    friend complex addCom(complex c1,complex c2);
    friend complex minusCom(complex c1,complex c2);
    friend complex outCom(complex c);
    private:
        double real;
        double imag;
    public:
        complex();
        complex(double r,double i);
};

int main(){

    return 0;
}