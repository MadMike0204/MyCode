#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Date
{
    protected:
        int year;
        int month;
        int day;
    public:
        Date(int year_in,int month_in,int day_in):
            year(year_in),month(month_in),day(day_in){}
};
class Time
{
    protected:
        int hour;
        int minute;
        int second;
    public:
        Time(int hour_in,int minute_in,int second_in):
            hour(hour_in),minute(minute_in),second(second_in){}
};
class Schedule:public Date,public Time
{
    bool friend before(const Schedule *s1,const Schedule *s2);
    private:    
        int id;
    public:
        Schedule(int id_in,int hour_in,int minute_in,int second_in,int year_in,int month_in,int day_in):
            Date(year_in,month_in,day_in),Time(hour_in,minute_in,second_in),id(id_in){}
        void display()
        {
            cout << "No." << id << ": "
                 << year << "/" 
                 << setfill('0') << setw(2) << month << "/"
                 << setw(2) << day << " "
                 << setw(2) << hour << ":"
                 << setw(2) << minute << ":"
                 << setw(2) << second << endl;
        }
};

bool before(const Schedule *s1,const Schedule *s2)//s1 < s2 则 返回1
{
    if(s1->year < s2->year)
    {
        return 1;
    }
    else if(s1->year > s2->year)
    {
        return 0;
    }
    else
    {
        if(s1->month < s2->month)
        {
            return 1;
        }
        else if(s1->month > s2->month)
        {
            return 0;
        }
        else
        {
            if(s1->day < s2->day)
            {
                return 1;
            }
            else if(s1->day > s2->day)
            {
                return 0;
            }
            else
            {
                if(s1->hour < s2->hour)
                {
                    return 1;
                }
                else if(s1->hour > s2->hour)
                {
                    return 0;
                }
                else
                {
                    if(s1->minute < s2->minute)
                    {
                        return 1;
                    }
                    else if(s1->minute > s2->minute)
                    {
                        return 0;
                    }
                    else
                    {
                        if(s1->second < s2->second)
                        {
                            return 1;
                        }
                        else if(s1->second > s2->second)
                        {
                            return 0;
                        }
                        else
                        {
                            if (s1->id < s2->id)
                                return 1;
                            else
                                return 0;
                        }
                    }
                }
            }
        }
    }
}

int test()
{
    Schedule a(2,2,2,2,2,2,2);
    a.display();
    return 1;
}

int main(){

    vector<Schedule*> Schedules;
    Schedule* to_Schedule;
    int id,h,min,s,y,month,d,count = 0;

    while(1)
    {
        cin >> id;
        if(id == 0)
        {
            break;
        }
        cin >> y >> month >> d >> h >> min >> s;
        to_Schedule = new Schedule(id,h,min,s,y,month,d);
        Schedules.push_back(to_Schedule);
        count++;
    }
    int flag;
    Schedule *temp = new Schedule(0,99,99,99,9999,99,99);
    for(int i=0;i<count;i++)
    {
        if(before(Schedules[i],temp))
        {
            flag = i;
            temp = Schedules[i];
        }
    }
    cout << "The urgent schedule is ";
    temp->display();



    return 0;
}
//Pass
/*
【id:283】【15分】D. 日程安排（多继承+友元函数）
时间限制
1s
内存限制
128MB
题目描述

已有一个日期类Date，包括三个protected成员数据year，month，day;

另有一个时间类Time，包括三个protected成员数据hour，minute，second，12小时制;

现需根据输入的日程的日期时间，安排前后顺序，为此以Date类和Time类为基类，建立一个日程类Schedule，包括以下新增成员：

int ID；//日程的ID

定义友元函数bool before(const Schedule & s1，const Schedule & s2);//判断日程s1时间是否早于日程s2。

编写主函数，根据输入的各项日程信息，建立日程对象，找出需要最早安排的日程(日期和时间相等时，输出较早建立的日程），并输出该日程对象的信息。


输入

测试输入包含若干日程，每个日程占一行（日程ID、日程日期、日程时间）。

当读入0时输入结束，相应的结果不要输出。


输出

时间最靠前的日程


IO模式

本题IO模式为标准输入/输出(Standard IO)，你需要从标准输入流中读入数据，并将答案输出至标准输出流中。

样例查看模式 
正常显示
查看格式
输入样例1 <-复制
1 2019 6 27 8 0 1
2 2019 6 28 8 0 1
3 2020 1 1 8 0 0
0

输出样例1
The urgent schedule is No.1: 2019/06/27 08:00:01
语言: 
C++
*/