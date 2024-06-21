#include <iostream>
using namespace std;

class Person
{
    private:
        int age;
    public:
        Person()
        {
            cout << "调用默认构造函数" << endl;
        }
        Person(Person &origin)
        {
            age = origin.age;
            cout << "调用拷贝函数" << endl;
        }
        Person(int aage)
        {
            age = aage;
            cout << "调用有参构造函数" << endl;
        }
        ~Person()
        {
            cout << "调用析构函数" << endl;
        }
};

void kko(Person jojo)
{
    return;
}

int main(){

    Person newnew;
    Person newnewnew(3);
    kko(newnew);

    return 0;
}