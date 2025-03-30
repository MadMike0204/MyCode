#include <iostream>
#include <iomanip>
using namespace std;

class Date{
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
        Date(int a=0,int b=0,int c=0):year(a),month(b),day(c){}
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
            cout << setw(2) << setfill('0') << month;
            cout << "/";
            cout << setw(2) << setfill('0') << day << endl;
        }
        
};

int Date::dayOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int Date::dayOfMonthLeap[13] = {1,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int a,b,c;
    int k = 1;
    int t;
    cin >> t;
    while(t--){
        Date* d;
        cin >> a >> b >> c;
        // 奇数构造
        if(k % 2){
            d = new Date(a,b,c);
        }
        else{
            d = new Date();
            d->setDate(a,b,c);
        }
        cout << "Today is ";
        d->print();
        d->addOneDay();
        cout << "Tomorrow is ";
        d->print();
        k++;
    }
}