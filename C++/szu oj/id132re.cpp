//头文件和类声明
#include <iostream>
using namespace std;

class MyDate {
private:
	int year;
	int month;
	int day;
public:
	MyDate(); //无参构造，默认日期2022-4-1，输出相关构造信息
	MyDate(int ty, int tm, int td); //有参构造，根据参数初始化，输出相关构造信息
	~MyDate(); 
	bool Before(MyDate &rd);
	void print()
	{ cout<<year<<"-"<<month<<"-"<<day; }
};
/////////////////////////////////////////////////////////
MyDate::MyDate()
{
        year = 2022;
        month = 4;
        day = 1;
        cout << "Date ";
        print();
        cout << " default constructed" << endl;
}
MyDate::MyDate(int ty,int tm,int td)
{
    year = ty;
    month = tm;
    day = td;
        cout << "Date ";
        print();
        cout << " constructed" << endl;
}
MyDate::~MyDate()
{
        cout << "Date ";
        print();
        cout << " destructed" << endl;
}
bool MyDate::Before(MyDate &rd)
{
            int flag = 0;
            if(rd.year < year)
            {
                flag = 1;
            }
            else if(rd.year == year && rd.month < month)
            {
                flag = 1;
            }
            else if(rd.year == year && rd.month == month && rd.day < day)
            {
                flag = 1;
            }
            return flag;
}
/////////////////////////////////////////////////////////
int main(){

    MyDate def;
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int year,month,day;
        cin >> year >> month >> day;
        MyDate target(year,month,day);
        if(target.Before(def))
        {
            def.print();
            cout << " before ";
            target.print();
            cout << endl;
        }
        else
        {
            target.print();
            cout << " before ";
            def.print();
            cout << endl;  
        }
    }
    return 0;
}
