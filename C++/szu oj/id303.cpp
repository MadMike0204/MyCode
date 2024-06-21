#include <iostream>
#include <iomanip> 
#include <vector>
using namespace std;

static int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
static int months_Leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
class Student;
class CDate
{
    friend class Student;
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

class Student
{
    friend int operator-(Student&,Student&);
    private:
        string name;
        CDate birthday;
    public:
        Student(string& n,int y,int m,int d):
            name(n)
        {
            CDate temp(y,m,d);
            birthday = temp;
        }
        string getName()
        {
            return name;
        }
};


int main(){

    vector<Student>students;

    int t;
    string name;
    cin >> t;
    int year,month,day;
    
    for(int i=0;i<t;i++)
    {
        cin >> name >> year >> month >> day;
        Student newst(name,year,month,day);
        students.push_back(newst);
    }
    int idx1,idx2,result=-1,temp;
    for(int i=0;i<t-1;i++)
    {
        for(int j=i;j<t;j++)
        {
            temp = students[i] - students[j];
            if(temp > result)
            {
                result = temp;
                idx1 = i;
                idx2 = j;
            }
        }  
    }
    cout <<students[idx1].getName() << "和" << students[idx2].getName() << "年龄相差最大，为" << result << "天。" << endl;
    
    return 0;
}

int operator-(Student&a,Student&b)
{
    return getInterval(a.birthday,b.birthday);
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
       return getInterval(b,a);
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