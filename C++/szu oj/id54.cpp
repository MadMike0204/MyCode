#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

double sigma(char str[],double a,double b);

int main()
{
	string s;
	double a,b;
	while(cin>>s>>a>>b)
	{
		if(s=="sin")
		cout<<sigma("sin",a,b)<<endl;
		else if(s=="cos")
		cout<<sigma("cos",a,b)<<endl;
		else cout<<sigma("tan",a,b)<<endl;
	}
}
double sigma(char str[],double a,double b)
{
    int i;
    double sum = 0;
    if(str[0] == 'c')
    {
        while((b-a) > -0.08)
        {
            sum += cos(a);
            a += 0.1;
        }
        return sum;
    }
    else if(str[0] == 's')
    {
        while((b-a) > -0.08)
        {
            sum += sin(a);
            a += 0.1;
        }
        return sum;
    }
    else if(str[0] == 't')
    {
        while((b-a) > -0.08)
        {
            sum += tan(a);
            a += 0.1;
        }
        return sum;
    }
}