#include <iostream>
#include <iomanip>
using namespace std;

class CClock
{
    private:
        int hour;
        int minute;
        int second;
        void correct()
        {
            int temp = second;
            if(second == 60)
            {
                second = 0;
                minute++;
                if(minute == 60)
                {
                    minute = 0;
                    hour++;
                    if(hour == 12)
                    {
                        hour = 0;
                    }
                }
            }
            else if(second == -1)
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
                    }
                }
            }
            return;
        }
        CClock operator ++ (int)
        {
            CClock temp = *this;
            this->second++;
            correct();
            return temp;
        }
        CClock operator -- ()
        {
            this->second--;
            correct();
            return *this;
        }
    public:
        CClock(int hour_,int minute_,int second_):
            hour(hour_),minute(minute_),second(second_){}
        CClock()
        {
            hour = 0;
            minute = 0;
            second = 0;
        }
        void changeClock(int x)
        {
            if(x > 0)
                for(int i=0;i<x;i++)
                {
                    (*this)++;
                }
            else if(x < 0)
                for(int i=0;i>x;i--)
                {
                    --(*this);
                }
        }
        void print()
        {
            cout << fixed << hour << ":" << minute << ":" << second << endl;
        }
};

void test()
{
    CClock testtt(11,59,59);
    testtt.changeClock(-5);
    testtt.print();
}

int main(){

    int hour,minute,second;
    cin >> hour >> minute >> second;
    CClock jojoClock(hour,minute,second);
    int t,op;
    cin >> t;
    while(t > 0)
    {
        cin >> op;
        jojoClock.changeClock(op);
        jojoClock.print();
        t--;
    }

    return 0;
}