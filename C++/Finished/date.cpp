#include <iostream>
using namespace std;

class CDate 
{
    private:
        int year, month, day;

    public:
        CDate(int y,int m,int d)
        {
            year = y;
            month = m;
            day = d;
        }
        bool check()
        {
            if(year < 1)
                return false;
            if(month < 1 || month > 12)
                return false;
            switch(day)
            {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    if(day < 1 || day > 31)
                        return false;
                    break;
                case 4: case 6: case 9: case 11:
                    if(day < 1 || day > 30)
                        return false;
                    break;
                case 2:
                    if(isLeap())
                        if(day < 1 || day > 29)
                            return false;
                    else
                        if(day < 1 || day > 28)
                            return false;
                    break;
            }
            return true;
        }
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