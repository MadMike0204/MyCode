#include <iostream>
using namespace std;


class Date;                 //对Date类的提前引用声明
class Time  {
  public:
      void display(Date &);    
      //display是成员函数，形参是Date类对象的引用
};
class Date  {                             
  public:
      friend void Time::display(Date &);    
      //声明Time中的display函数为友元成员函数
};

int main() {

    return 0;
}