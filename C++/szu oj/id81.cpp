#include <iostream>
#include <cmath>
using namespace std;
int gcd(int x,int y){
    int t,r;
    if(x < y){
        t = x;
        x = y;
        y = t;
    }
    while((x%y) != 0){
        r = x%y;
        x = y;
        y = r;
    }
    return y;
}
int lcm(int x,int y){
    return (x*y)/gcd(x,y);
}
class CFraction
{
    private:
        int fz, fm;
    public:
        CFraction(int fz_val, int fm_val):fz(fz_val),fm(fm_val){}
        CFraction add(const CFraction &r);
        CFraction sub(const CFraction &r);
        CFraction mul(const CFraction &r);
        CFraction div(const CFraction &r);
        int getGCD();   // 求对象的分子和分母的最大公约数
        void print();
};

void CFraction::print(){
    cout << fz << "/" << fm << endl;
}

int CFraction::getGCD(){
    return gcd(fz,fm);
}
// a/b
CFraction CFraction::add(const CFraction &r){
    int b = lcm(fm,r.fm);
    int a = fz * (b/fm) + r.fz * (b/r.fm);
    int c = gcd(a,b);

    CFraction temp(a/c,b/c);
    return temp;
}

CFraction CFraction::sub(const CFraction &r){
    int b = lcm(fm,r.fm);
    int a = fz * (b/fm) - r.fz * (b/r.fm);
    int c = abs(gcd(a,b));

    CFraction temp(a/c,b/c);
    return temp;
}

CFraction CFraction::mul(const CFraction &r){
    int b = fm * r.fm;
    int a = fz * r.fz;
    int c = gcd(a,b);

    CFraction temp(a/c,b/c);
    return temp;
}

CFraction CFraction::div(const CFraction &r){
    int b = fm * r.fz;
    int a = fz * r.fm;
    int c = gcd(a,b);

    CFraction temp(a/c,b/c);
    return temp;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int a,b;
        scanf("%d/%d",&a,&b);
        CFraction fracA(a,b);
        scanf("%d/%d",&a,&b);
        CFraction fracB(a,b);

        CFraction temp = fracA.add(fracB);
        temp.print();
        temp = fracA.sub(fracB);
        temp.print();
        temp = fracA.mul(fracB);
        temp.print();
        temp = fracA.div(fracB);
        temp.print();
        cout << endl;
    }

    return 0;
}