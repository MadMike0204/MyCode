#include <iostream>
#include <iomanip>
using namespace std;

class Cdate
{
    private:
        int hour,minute,second;
    public:
        Cdate(int hour,int minute,int second)
        {
            this->hour = hour;
            this->minute = minute;
            this->second = second;
        }
        void set()
        {
            cin >> hour >> minute >> second;
        }
        void print()const
        {
            cout 
            << setw(2) << setfill('0') << hour << ":" 
            << setw(2) << setfill('0') << minute << ":" 
            << setw(2) << setfill('0') << second << endl;
        }
        friend ostream & operator << (ostream & stream,
                                      const Cdate &date);
        friend istream & operator >> (istream & stream,
                                      const Cdate &date);
};
ostream & operator << (ostream & stream,
                                      const Cdate &date)
{
    date.print();
    return stream;
}
istream & operator >> (istream & stream,
                                      Cdate &date)
{
    date.set();
    return stream;
}

void test()
{
    Cdate jojo(1,2,3),josef(2,3,4),jos(6,7,8);
    jojo.print();
    cout << jojo << josef << jos << endl;
}

int main(){

    Cdate jostar(5,5,5);
    cin >> jostar;
    jostar.print();

    return 0;
}

jostar = jojo;