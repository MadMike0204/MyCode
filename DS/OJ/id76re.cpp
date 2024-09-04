#include <iostream>
using namespace std;

static string Statement[2] = {"close","open"};

struct Stock
{
    int year,month,day;
    bool state;
    int s1,s2;
    Stock()
    {
        year = month = day = state = s1 = s2 = 0;
    }
    void Set(int year,int month,int day,int s1,int s2,string s)
    {
        this->year = year;
        this->day = day;
        this->month = month;
        this->s1 = s1;
        this->s2 = s2;
        if(s == "open")
            state = 1;
        else
            state = 0;
    }
    Stock(const Stock& j)
    {
        
    }
};

int main(){

    return 0;
}