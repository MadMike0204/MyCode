#include <iostream>
#include <iomanip>
using namespace std;

static int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

static int months_Leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

class Pet;class Dog;class Cat;
class CDate
{
    friend int getInterval(CDate &a,CDate &b);
    private:
        int year;
        int month;
        int day;
    public:
        CDate(){}
        CDate(int h,int m,int d):
            year(h),month(m),day(d){}
        bool isLeap()
        {   
            bool flag = 0;
            if(year % 4 == 0)
                if(year % 100 == 0)
                    if(year % 400 == 0)
                        flag = 1;
            return flag;
        }
        void print()
        {
            cout << year << " " << month << " " << day << endl;
        }
};
int getDays(int year,int month,int day);
bool isLeap(int year);
class Pet
{ 
    protected:
        string name;//姓名
        float length;//身长
        float weight;//体重
        CDate current;//开始记录时间
    public:
        virtual void display(CDate day)=0;//输出目标日期时宠物的身长和体重
};
class Cat:public Pet
{
    friend class CDate;
    public:
        Cat(string &n,float l,float w,CDate &c)
        {
            name = n;
            length = l;
            weight = w;
            current = c;
        }
        virtual void display(CDate day)
        {
            int interval = getInterval(current,day);
            if(interval < 0)
            {
                cout << "error" << endl;
                return;
            }
            length += 0.1 * interval;
            weight += 0.2 * interval;
            cout << name << " after " 
                 << interval
                 << " day: ";
            cout << fixed << setprecision(2) 
                 << "length=" << length 
                 << ",weight=" << weight << endl;
        }
};
class Dog:public Pet
{
    friend class CDate;
    public:
        Dog(string &n,float l,float w,CDate &c)
        {
            name = n;
            length = l;
            weight = w;
            current = c;
        }
        virtual void display(CDate day)
        {
            int interval = getInterval(current,day);
            if(interval < 0)
            {
                cout << "error" << endl;
                return;
            }
            length += 0.2 * interval;
            weight += 0.1 * interval;
            cout << name << " after " 
                 << interval
                 << " day: ";
            cout << fixed << setprecision(2) 
                 << "length=" << length 
                 << ",weight=" << weight << endl;
        }
};

int main(){

    Pet* jojo = NULL;
    string name;
    float weight,length;
    int t,type;
    cin >> t;
    int sy,sn,sd;
    cin >> sy >> sn >> sd;
    CDate original(sy,sn,sd);
    while(t > 0)
    {
        cin >> type >> name >> length 
            >> weight >> sy >> sn >> sd;
        CDate current(sy,sn,sd);
        if(type == 1)
        {
            jojo = new Cat(name,length,weight,current);
        }
        else 
        {
            jojo = new Dog(name,length,weight,current);
        }
        jojo->display(original);
        t--;
    }

    return 0;
}

int getInterval(CDate &a,CDate &b) // a is later than b
{
    bool flag = 1;
    int delta_day = a.day - b.day;
    int delta_month = a.month - b.month;
    int delta_year = a.year - b.year;
    if(delta_year < 0 
    || delta_year == 0 && delta_month < 0 
    || delta_year == 0 && delta_month == 0 && delta_day < 0)
    {
       return -1; 
    }

    int days_a = getDays(a.year,a.month,a.day);
    int days_b = getDays(b.year,b.month,b.day);

    if(delta_year == 0)
    {
        return days_a - days_b;
    }
    else
    {
        int day_y = 0;
        for(int i=0;i<delta_year;i++)
        {
            if(isLeap(b.year + i))
            {
                day_y += 366;
            }
            else
            {
                day_y += 365;
            }
        }
        return day_y + days_a - days_b;
    }
}

int getDays(int year,int month,int day)
{
    if(isLeap(year))
    {
        for(int i=0;i<month-1;i++)
        {
            day += months_Leap[i];
        }
    }
    else
    {
        for(int i=0;i<month-1;i++)
        {
            day += months[i];
        }
    }
    return day;
}
bool isLeap(int year)
{   
    bool flag = 0;
    if(year%4 == 0 && year%100 != 0)
        flag = 1;
    else if(year % 400 == 0)
        flag = 0;
    return flag;
}