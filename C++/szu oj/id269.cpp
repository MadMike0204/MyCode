#include <iostream>
using namespace std;
class A{
	public:
		A(){
			cout<<"I am A\n";
		}
};
class B{
	public:
		B(){
			cout<<"I am B\n";
		}
};
class P1{
	public:
		P1(){
			cout<<"I am P1\n";
		}
};
class P2{
	public:
		P2(){
			cout<<"I am P2\n";
		}
};
class P3{
	public:
		P3(){
			cout<<"I am P3\n";
		}
}; 
class P4{
	public:
		P4(){
			cout<<"I am P4\n";
		}
};
class Test:virtual public P2,virtual public P4,public P1,public P3,public A,public B
{
    public:
        Test()
        { 
        }
};
int main()
{
	cin.get();
	Test t;
}
