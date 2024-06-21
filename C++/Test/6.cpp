#include <iostream>
using namespace std;

struct DateX
{
    int year;
    int month;
    int day;
    long long idk;
};


int main(){

    DateX day0 = {2024,3,28,114514};
    DateX day1 = day0;
    day1.day = 27;
    day1.month = 3;
    day1.year = 2024;

    cout << day1.year << "." << day1.month << "." << day1.day << "." << day1.idk << endl;
    cout << &day1 << ": " << &day1.year << "." << &day1.month << "." << &day1.day << endl;
    cout << sizeof(day1) << ": " << sizeof(day1.year) << "." << sizeof(day1.month) << "." << sizeof(day1.day) << "." 
         << sizeof(day1.idk) << endl;
    return 0;
}