#include <iostream>
#include <iomanip>
using namespace std;

class CDate
{
    private:
        int day,month,year,x;
    public: 
        CDate()
        {
            x = 0;
            day = 0;
            month = 0;
            year = 0;
        }
        CDate(int x)
        {
            this->x = x;
            this->day = x % 100;
            x = (x - day) / 100;
            this->month = x % 100;
            x = (x - month) / 100;
            this->year = x;
        }
        void operator = (int x)
        {
            this->x = x;
            this->day = x % 100;
            x = (x - day) / 100;
            this->month = x % 100;
            x = (x - month) / 100;
            this->year = x;
        }
        operator int()
        {
            return x;
        } 
        void Print()
        {
            cout << year << "年" << 
            setw(2) << setfill('0') << month << "月" << 
            setw(2) << setfill('0') << day << "日" << endl;
        }
};
int main()
{
    int t, t1, t2;
    CDate C1, C2;
    cin>>t;
    while (t--)
    {
        cin>>t1>>t2;
        C1 = t1;
        C2 = t2;
        ((C1>C2)?C1:C2).Print();//日期大的输出，在代码C1>C2中，会自动把C1和C2转换为整数进行比较
    }
    return 0;
}