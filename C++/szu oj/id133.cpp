//头文件和日期类声明
#include<iostream>
#include<iomanip>
using namespace std;
 
class TDate {
private:
    int year,month,day;
public:
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}
    void set(int y,int m,int d);
    void print();
    void addOneDay();
};

//----在以下区域完成部分成员函数的类外定义----
/********** Write your code here! **********/

void TDate::set(int y,int m,int d)
{
    year = y;
    month = m;
    day = d;
}
void TDate::addOneDay()
{
    day++;
    if(day <= 28)
    {
        return;
    }
    int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool flag = 0;
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        flag = 1;
    }
    arr[2] += flag;
    if(arr[month] < day)
    {
        month++;
        day = 1;
    }
    if(month > 12)
    {
        month = 1;
        year++;
    }
}
void TDate::print()
{
    int x = 100000000;
    x += day;
    x += (month * 100);
    x += (year * 10000);
    x -= 100000000;
    cout << x;
}
/*******************************************/
//主函数如下
int main()
{   int t, y,m,d;
    cin>>t;
    while(t--)
    {	TDate d1;
		cin>>y>>m>>d;
		d1.set(y, m, d);
        cout<<"Today-";
        d1.print();
        d1.addOneDay();
        cout<<" Tomorrow-";
        d1.print();
		cout<<endl;
    }
    return 0;
}
