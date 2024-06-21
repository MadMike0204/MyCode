#include <iostream>
#include <cmath>
using namespace std;

double sigma(double (*F)(double), double a, double b) {
    double sum = 0;
    for (double x = a; x < b; x += 0.1) {
        sum += F(x);
    }
    return sum;
}

int main()

{
	string s;
	double a,b;
	while(cin>>s>>a>>b)
	{
		if(s=="sin")
		cout<<sigma(sin,a,b)<<endl;
		else if(s=="cos")
		cout<<sigma(cos,a,b)<<endl;
		else cout<<sigma(tan,a,b)<<endl;
	}
}