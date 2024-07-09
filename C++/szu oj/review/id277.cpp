#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class CCar
{
    protected:
        int rent;
        int seats;
        double mass;
    public:
        CCar(int r=0,int s=0,double m=0):rent(r),seats(s),mass(m){}
        int GetPrice(int d)
        {
            return d * rent;
        }
        int GetSeats(int d)
        {
            return seats * d;
        }
        double GetMass(int d)
        {
            return mass * d;
        }
};
class Bus:virtual public CCar
{   
    public:
        Bus(int r=0,int s=0):CCar(r)
        {
            seats = s;
        }
};
class Truck:virtual public CCar
{
    public:
        Truck(int r=0,double m=0):CCar(r)
        {
            mass = m;
        }
};
class Pickup:public Bus,public Truck
{
    public:
        Pickup(int r,int s,double m):CCar(r),Bus(r,s),Truck(r,m){}
};

vector<CCar*> CreateCars()
{
    vector<CCar*> Cars;
    CCar* M[10] = {new Bus(800,5),new Bus(400,5),
                   new Bus(800,5),new Bus(1300,51),
                   new Bus(1500,55),new Pickup(500,5,0.45),
                   new Pickup(450,5,2),new Truck(200,3),
                   new Truck(1500,25),new Truck(2000,35)};
    for(int i=0;i<10;i++)
    {
        Cars.push_back(M[i]);
    }

    return Cars;
}

void test(){

    vector<CCar*> JoCars = CreateCars();
    for(CCar* element : JoCars)
    {
        cout << element->GetPrice(1) << endl;
    }
}
int main(){

    int x,N,id,day,seats,rent;
    double mass;
    vector<CCar*> JoCars = CreateCars();
    while(cin >> x)
    {
        if(x == 0)
        {
            cout << "0 0.00 0" << endl;
            break;
        }

        cin >> N;
        seats = rent = 0;
        mass = 0.0001;
        for(int i=0;i<N;i++)
        {
            cin >> id >> day;
            rent += JoCars[id-1]->GetPrice(day);
            mass += JoCars[id-1]->GetMass(day);
            seats += JoCars[id-1]->GetSeats(day);
        }
        cout << seats << " ";
        cout << fixed << setprecision(2) << mass << " ";
        cout << rent << endl;
    }

    return 0;
}