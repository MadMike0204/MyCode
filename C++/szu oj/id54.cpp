#include <iostream>
#include <cmath>
using namespace std;

double sigma(char* str,double a,double b);
int main()

{
	string s;
	double a,b;
	while(cin>>s>>a>>b)
	{
		if(s=="sin")
		    cout<<sigma(&s[0],a,b)<<endl;
		else if(s=="cos")
		    cout<<sigma(&s[0],a,b)<<endl;
		else 
            cout<<sigma(&s[0],a,b)<<endl;
	}
}

double sigma(double (*Func)(double), double a, double b) {
    double sum = 0;
    // 以0.1为步长计算指定范围内的三角函数之和
    for (double x = a; x < b; x += 0.1) {
        sum += Func(x);
    }
    return sum;
}