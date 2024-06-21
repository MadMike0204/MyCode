#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

struct Mike{
    int age;
    int height;
};


void test_1();
void test_2();
void test_3();
void test_4();
void test_5();

int main(){

    test_5();
    return 0;
}

void test_1()
{
    int x = 5;
    int y(5.4); //不会检查参数是否符合
    //int z{5.4}; //会检查
    std::cout << "x=" << x << endl
              << "y=" << y << endl;
 // std::coout           << "z=" << z << endl;
}

void test_2()//Uniform initialization -- Map
{
    std::map<std::string,int> ages{
        {"JOJO",22},
        {"JOker",287}
    };
    std::cout << "JOJO:" << ages["JOJO"] << endl
              << "JOker:" << ages.at("JOker") << endl;
}

void test_3()//Uniform initialization -- Vector
{
    std::vector<int> numbers{1,2,3,4,5};
    for(int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void test_4()//structed Binding
{
    Mike Me{19,186};
    std::cout << "Age " << Me.age << " Height" << Me.height << endl;
}
//structed Binding
/*
● A useful way to initialize some variables from data 
structures with fixed sizes at compile time
● Ability to access multiple values returned by a function
*/
//Example:
std::tuple<std::string,std::string,std::string> getClassInfo(){
    std::string className = "CS106L";
    std:string buildingName = "Turing Auditorium";
    std::string language = "C++";
    return {className,buildingName,language};
}
void test_5()
{
    auto [className,buildingName,language] = getClassInfo();
    std::cout << "Come to " << buildingName << " and join us for " << className
              <<" to learn " << language << "!" << std::endl;
}
//L values and R values
void test_6()
{
    int x = 25;//25 is a R value : only can be right : temporary
    int j = x;// x is a L value : can be right or left

}
void test_7()
{
    const int R = 25;//  √
    const int& x = R; // √
 // int& m = R;      //  × 一个const常量不能被一个 非const引用 引用
}