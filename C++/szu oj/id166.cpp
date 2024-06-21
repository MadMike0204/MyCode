#include <iostream>
#include <iomanip>
using namespace std;
class CTime;
class CDate
{
    private:
        int year;
        int month;
        int day;
    public:
        CDate(int year_in,int month_in,int day_in):
            year(year_in),month(month_in),day(day_in){}
    friend void Display(CTime &T,CDate &D);
};

class CTime
{
    private:
        int hour;
        int minute;
        int second;
    public:
        CTime(int hour_in,int minute_in,int second_in):
            hour(hour_in),minute(minute_in),second(second_in){}
    friend void Display(CTime &T,CDate &D);
};

void Display(CTime &T,CDate &D)
{
    cout << D.year << "-" 
         << std::setfill('0') << std::setw(2) 
         << D.month << "-"
         << std::setfill('0') << std::setw(2)
         << D.day << " "
         << std::setfill('0') << std::setw(2)
         << T.hour << ":"
         << std::setfill('0') << std::setw(2)
         << T.minute << ":"
         << std::setfill('0') << std::setw(2)
         << T.second << endl;
}
int main(){

    int t,a,b,c;
    cin >> t;
    while(t>0)
    {
        cin >> a >> b >> c;
        CDate newnew(a,b,c);
        cin >> a >> b >> c;
        CTime cancanneed(a,b,c);
        Display(cancanneed,newnew);
        t--;
    }
    

    return 0;
}