#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Car
{
    protected:
        int id;
        int rent;
    Car(){};
    Car(int id_in,int rent_in):
        rent(rent_in),id(id_in){}
};

class Coach:virtual public Car
{
    protected:
        int passengers;
    public:
        Coach(){}
        Coach(int id_in,int rent_in,int passengers_in):
            Car(id_in,rent_in),passengers(passengers_in){}
};
class Truck:virtual public Car
{
    protected:
        float mass;
    public:
        Truck(){};
        Truck(int id_in,int rent_in,float mass_in):
            Car(id_in,rent_in),mass(mass_in){}
};
class Pickup:public Coach,public Truck
{
    public:
        Pickup(int id_in,int rent_in,int passengers_in,float mass_in)
        {
            id = id_in;
            rent = rent_in;
            passengers = passengers_in;
            mass = mass_in;
        }
        Pickup(Pickup &copy)
        {
            rent = copy.rent;
            passengers = copy.passengers;
            mass = copy.mass;
        }
};

void initialize(vector<void*> &Cars)
{
    Coach* a = new Coach(1,800,5);
    Cars.push_back(a);

    a = new Coach(2,400,5);
    Cars.push_back(a);

    a = new Coach(3,400,5);
    Cars.push_back(a);

    a = new Coach(4,1300,51);
    Cars.push_back(a);

    a = new Coach(5,1500,55);
    Cars.push_back(a);

    Pickup* b = new Pickup(6,500,5,0.45);
    Cars.push_back(b);

    b = new Pickup(7,450,5,2.0);
    Cars.push_back(b);

    Truck* c = new Truck(8,400,0.45);
    Cars.push_back(c);

    c = new Truck(9,1500,25);
    Cars.push_back(c);

    c = new Truck(10,2000,35);
    Cars.push_back(c);

}

int main(){

    bool yes_or_no;
    cin >> yes_or_no;
    if(!yes_or_no)
        return 0;

    vector<void*> Cars;
    initialize(Cars);
    int N;
    cin >> N;
    int id,day;
    int total_bill = 0,total_passenger = 0;
    float total_mass = 0;
    void* CC = Cars[2];
    for(int i=0;i<N;i++)
    {
        cin >> id >> day;
    }
    return 0;
}