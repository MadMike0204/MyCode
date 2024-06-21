#include <iostream>
using namespace std;

class Vehicle
{ 
    protected:
        string no;//编号
    public:
        virtual void display()=0;//应收费
};
class Car:public Vehicle
{
    protected:
        int passenger;
        int mass;
    public:
        Car(string no_,int p,int m):
            passenger(p),mass(m)
        {
            no = no_;
        }
        virtual void display()
        {
            cout << no << " " << passenger * 8 + mass * 2 << endl; 
        }
};
class Truck:public Vehicle
{
    protected:
        int mass;
    public:
        Truck(string no_,int m):
            mass(m)
        {
            no = no_;
        }
        virtual void display()
        {
            cout << no << " " << mass * 5 << endl; 
        }
};
class Bus:public Vehicle
{
    protected:
        int passenger;
    public:
        Bus(string no_,int p):
            passenger(p)
        {
            no = no_;
        }
        virtual void display()
        {
            cout << no << " " << passenger * 3 << endl; 
        }
};

int main(){

    int t,p,m;
    char type;
    string no;
    cin >> t;
    Vehicle *pv;
    while(t > 0)
    {
        cin >> type;
        if(type == '1')
        {
            cin >> no >> p >> m;
            Car jojo(no,p,m);
            pv = &jojo;
            pv->display();
        }
        if(type == '2')
        {
            cin >> no >> m;
            Truck jojo(no,m);
            pv = &jojo;
            pv->display();
        }
        if(type == '3')
        {
            cin >> no >> p;
            Bus jojo(no,p);
            pv = &jojo;
            pv->display();
        }
        t--;
    }

    return 0;
}