//头文件区域
#include <iostream>
using namespace std;
//填空区域1：类CDate的定义
/********** Write your code here! **********/
class CDate{
    private:
        int day,month,year;
        bool isLeap()
        {   
            bool flag = 0;
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                flag = 1;
            return flag;
        }
        void updateDate(){
            if( (day > dayOfMonth[month] && !isLeap()) || 
                (day > dayOfMonthLeap[month] && isLeap())){
                day = 1;
                month += 1;
                if(month > 12){
                    month = 1;
                    year += 1;
                }
            }
        }
    public:
        static int dayOfMonthLeap[13];
        static int dayOfMonth[13];
        CDate(int a=0,int b=0,int c=0):year(c),month(b),day(a){}
        CDate(CDate& c){
            day = c.day+1;
            month = c.month;
            year = c.year;
            updateDate();
        }
        void setDate(int year,int month,int day){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        void addOneDay(){
            day++;
            updateDate();
        }
        int getYear(){
            return year;
        }
        int getMonth(){
            return month;
        }
        int getDay(){
            return day;
        }
        void print(){
            cout << year << "/";
            cout << month;
            cout << "/";
            cout << day << endl;
        }
};

int CDate::dayOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int CDate::dayOfMonthLeap[13] = {1,31,29,31,30,31,30,31,31,30,31,30,31};

/*******************************************/
//主函数区域
int main()
{	int a,b,c;
	cin>>a>>b>>c;
	CDate d1(a,b,c);
	CDate d2=d1;
	CDate d3(d2);
	d1.print();
	d2.print();
	d3.print();
	return 0;
}

