#include <iostream>
using namespace std;

class Person
{
    private:
        int a;
        int b;
    public:
    Person(int aa,int bb):
        a(aa),b(bb){}
    Person()
    {
        a = 0;
        b = 0;
    }
    Person operator + (Person &x)
    {
        Person temp;
        temp.a = this->a + x.a;
        temp.b = this->b + x.b;
    }
};


int main(){

    Person jojo(233,233);
    Person jostar(114,514);



    return 0;
}