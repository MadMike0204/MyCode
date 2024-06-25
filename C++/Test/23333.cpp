#include <iostream>
using namespace std;
class Animal //抽象类
{
	public: void virtual print(ostream& o)=0; //纯虚函数 
};
class Dog:public Animal
{
	public: void print(ostream& o)
	{o<<"I am a dog,汪汪," <<endl;}
};
class Cat:public Animal
{
	public: void print(ostream& o)
	{o<<"I am a cat,喵喵" <<endl;}
};
ostream& operator<<(ostream& o,Animal& p)
{
    p.print(o);
    return o;
}
int main(){

    Dog dog;
    Cat cat;
    cout << dog << cat;
    return 0;
}