#include <iostream>
using namespace std;
class B;
class A
{
    private:
        string name;
        int age;
    public:
        A()
        {
            name = "碟";
            age = 52;
        }
    friend void B::specific_A(A& x);
};

class B
{
    private:
        int length;
        int width;
    public:
        B()
        {
            length = 8;
            width = 9;
        }
        void specific_A(A& x)
        {
            cout << "B 访问了 A 的私有成员" << endl 
                 << "name:" << x.name << endl
                 << "age:" << x.age << endl; 
        }
};

int main(){



    return 0;
}