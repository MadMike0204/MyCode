#include<iostream>
using namespace std;

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

complex::complex(){
    real = 0;
    imag = 0;
}

complex::complex(double r,double i){
    real = r;
    imag = i;
}

complex addCom(complex c1,complex c2){
    complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

complex minusCom(complex c1,complex c2){
    complex temp;
    temp.real = c1.real - c2.real;
    temp.imag = c1.imag - c2.imag;
    return temp;
}

complex outCom(complex c){
    cout << "(" << c.real << "," << c.imag << ")" << endl;
    return c;
}

int main(){
    double real, imag;
    cin >> real >> imag;
    complex result(real, imag);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        char op;
        cin >> op >> real >> imag;
        complex c2(real, imag);
        
        if(op == '+'){
            result = addCom(result, c2);
        }
        else if(op == '-'){
            result = minusCom(result, c2);
        }
        
        outCom(result);
    }
    
    return 0;
}
