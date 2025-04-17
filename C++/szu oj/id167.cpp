#include <iostream>
#include <cmath>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;
    
public:
    Time(int h, int m, int s);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    friend int timeDifference(const Time* t1, const Time* t2);
};

Time::Time(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
}
int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}
int timeDifference(const Time* t1, const Time* t2) {
    int seconds1 = t1->hour * 3600 + t1->minute * 60 + t1->second;
    int seconds2 = t2->hour * 3600 + t2->minute * 60 + t2->second;
    
    return abs(seconds1 - seconds2);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        
        Time t1(h1, m1, s1);
        Time t2(h2, m2, s2);
        
        int diff = timeDifference(&t1, &t2);
        
        cout << h1 << "时" << m1 << "分" << s1 << "秒--" 
             << h2 << "时" << m2 << "分" << s2 << "秒时间差为" 
             << diff << "秒" << endl;
    }
    
    return 0;
}
