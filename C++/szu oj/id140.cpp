#include <iostream>
using namespace std;

class Date{
    private:
        int day,month,year;
        bool isLeap()
        {   
            bool flag = 0;
            if(year % 4 == 0)
                if(year % 100 == 0)
                    if(year % 400 == 0)
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
        Date(){};
        void set(int year,int month,int day){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        void nextDay(){
            day++;
            updateDate();
        }
        
        void print(){
            cout << year << "/" << month << "/" << day << endl;
        }
        
};

int Date::dayOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int Date::dayOfMonthLeap[13] = {1,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
    Date s;
    s.set(a,b,c);
    s.nextDay();
    s.print();
    }
}