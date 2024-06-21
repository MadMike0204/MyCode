#include <iostream>
using namespace std;
class NewNew
{     
    public:
        mutable int age;
        NewNew(int age)
        {
            this->age = age;
        }
        NewNew& NNaddNN(NewNew &p)
        {
            this->age += p.age;
            return *this;
        }
};
void test1()
{
    NewNew p1(18);
    cout << "Age:" << p1.age << endl;
}
//this 指针 指向被调用的成员函数 所属的对象
//返回对象本身用*this
void test2()
{
    NewNew p1(23);
    NewNew p2(23);
    p2.NNaddNN(p1).NNaddNN(p1).NNaddNN(p1);//链式编程思想
    cout << "Age:" << p2.age << endl;
}
void test3()
{

}
int main(){
    test3();
    return 0;
}