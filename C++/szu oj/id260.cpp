#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
    protected:
        int hour;
        int minute;
        int second;
    public:
        Time(int hour_,int minute_,int second_):
            hour(hour_),minute(minute_),second(second_){}
};
class Time12:public Time
{
    private:
        string interval;
    public:
        Time12(int hour_,int minute_,int second_):
            Time(hour_,minute_,second_){}
        void set(int m)
        {
            if(m == 1)
            {
                interval = "AM";
            }
            else
            {
                interval = "PM";
            }
        }
        void change()
        {
            if(interval[0] == 'P')
                interval = "AM";
            else
                interval = "PM";
        }
        void minus()
        {
            second--;
            if(second == -1)
            {
                second = 59;
                minute--;
                if(minute == -1)
                {
                    minute = 59;
                    hour--;
                    if(hour == -1)
                    {
                        hour = 11;
                        change();
                    }
                }
            }

        }
        void add()
        {
            second++;
            if(second%60 == 0)
            {
                second = 0;
                minute++;
                if(minute%60 == 0)
                {
                    minute = 0;
                    hour++;
                    if(hour%12 == 0)
                    {
                        hour = 0;
                        change();
                    }
                }
            }
        }
        void display()
        {
            cout << interval << " "
            << setw(2) << setfill('0') << hour << ":" 
            << setw(2) << setfill('0') << minute << ":" 
            << setw(2) << setfill('0') << second << endl;
        }
};

int main(){

    int number,h,m,s;
    char op;
    while(1)
    {
        cin >> number;
        if(number == 0)
            break;
        cin >> h >> m >> s;
        Time12 jojo(h,m,s);
        jojo.set(number%120);
        cin >> op >> number;
        if(op == '+')
        {
            for(int i=0;i<number;i++)
            {
                jojo.add();
            }
        }
        else
        {
            for(int i=0;i<number;i++)
            {
                jojo.minus();
            }
        }
        jojo.display();
    }

    return 0;
}