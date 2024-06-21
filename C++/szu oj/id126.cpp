#include <iostream>
#include <string>
using namespace std;

static const char sswtype[3][15] = {"original","trial","backup"};
static const char storetypee[3][15] = {"optical disk","hard disk","USB disk"};

class CDate
{
    private:
        int year,month,day;
    public:
        CDate()
        {
            year = 0;
            month = 0;
            day = 0;
        }
        CDate(int y, int m, int d)
        {
            year = y; month = m; day = d; 
        }
        bool isLeapYear() 
        {
            return (year%4 == 0 && year%100 != 0) || year%400 == 0; 
        }
        int getYear() 
        {
             return year; 
        }
        int getMonth() 
        {
            return month; 
        }
        int getDay() 
        {
            return day; 
        }
        int getDayofYear()         //计算日期从当年1月1日算起的天数
        {
            int i, sum=day;
            int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
            int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

            if (isLeapYear())
                for(i=0;i<month;i++)   
                    sum +=b[i];
            else
                for(i=0;i<month;i++)   
                    sum +=a[i];
            return sum;
        }
};

class SSW
{
    private:
        string name;
        char sw_type;
        CDate valid_date;
        char store_type;
    public:
        SSW(SSW &p)
        {
            name = p.name;
            sw_type = 'B';
            valid_date = p.valid_date;
            store_type = 'H';
        }
        SSW(string namein,char sw_typein,char store_typein,int year,int month,int day)
        {
            name = namein;
            sw_type = sw_typein;
            store_type = store_typein;
            valid_date = CDate(year,month,day); 
        }
        int validDays()
        {
            CDate datt(2015,4,7);
            if(valid_date.getYear() == 0 && valid_date.getDay() == 0 && valid_date.getMonth() == 0)
            {
                return -2;
            }   
            else if(valid_date.getDayofYear() > datt.getDayofYear())
            {
                return valid_date.getDayofYear() - datt.getDayofYear();
            }
            else if(valid_date.getDayofYear() <= datt.getDayofYear())
            {
                return -1;
            }
            return 0;
        }
        void Print()
        {
            int a=-1,b=-1;
            switch(sw_type)
            {
                case 'B':
                    a++;
                case 'T':
                    a++;
                case 'O':
                    a++;
            }
            switch(store_type)
            {
                case 'U':
                    b++;
                case 'H':
                    b++;
                case 'D':
                    b++;
            }
            cout << "name:" << name << endl
                 << "type:" << sswtype[a] << endl
                 << "media:" << storetypee[b] << endl;
            int flag = validDays();
            if(flag > 0)
            {
                cout << "this software is going to be expired in " << flag << " days" << endl; 
            }
            else if(flag == -1)
            {
                cout << "this software has expired" << endl;
            }
            else if(flag == -2)
            {
                cout << "this software has unlimited use" << endl;
            }
            cout << endl;
        }
};

int main(){

    int t;
    cin >> t;
    string name;
    char swtype,storetype;
    int year,month,day;
    while(t > 0)
    {   
        cin >> name >> swtype >> storetype >> year >> month >> day;
        SSW sw(name,swtype,storetype,year,month,day);
        sw.Print();
        SSW sww(sw);
        sww.Print();

        t--;
    }
    return 0;
}