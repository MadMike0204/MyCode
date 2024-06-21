#include <iostream>
using namespace std;

class Animal
{
    protected:
        int age;
        string name;
    public:
        Animal(int a,const string &n):
            age(a),name(n){}
        virtual void Speak(){}
};
class Tiger:public Animal
{
    public:
        Tiger(int a,const string &n):
            Animal(a,n){}
        virtual void Speak()
        {
            cout << "Hello,I am " << name << ",AOOO." << endl;
        }
};
class Dog:public Animal
{
    public:
        Dog(int a,const string &n):
            Animal(a,n){}
        virtual void Speak()
        {
            cout << "Hello,I am " << name << ",WangWang." << endl;
        }
};
class Duck:public Animal
{
    public:
        Duck(int a,const string &n):
            Animal(a,n){}
        virtual void Speak()
        {
            cout << "Hello,I am " << name << ",GAGA." << endl;
        }
};
class Pig:public Animal
{
    public:
        Pig(int a,const string &n):
            Animal(a,n){}
        virtual void Speak()
        {
            cout << "Hello,I am " << name << ",HENGHENG." << endl;
        }
};

int main(){

    int t,age,k;
    string name;
    string kind,kinds[4] = {"Tiger","Pig","Dog","Duck"};
    Animal* jostar = NULL;
    cin >> t;
    while(t > 0)
    {
        t--;
        k = -1;
        cin >> kind;
        for(int i=0;i<4;i++)
        {
            if(kind == kinds[i])
            {
                k = i;
                break;
            }
        }
        cin >> name >> age;
        if(k < 0)
        {
            cout << "There is no " << kind << " in our Zoo." << endl;
            continue;
        }
        else if(k == 0)
        {
            jostar = new Tiger(age,name);
        }
        else if(k == 1)
        {
            jostar = new Pig(age,name);
        }
        else if(k == 2)
        {
            jostar = new Dog(age,name);
        }
        else if(k == 3)
        {
            jostar = new Duck(age,name);
        }
        jostar->Speak();
    }

    return 0;
}