#include <iostream>
using namespace std;

class Employee
{
    protected:
        string name;
        string position;
        int grade;
        int year;
    public:
        Employee(string &n,string &p,int g,int y):
            name(n),position(p),grade(g),year(y){}
        virtual void salary()
        {
            int salary = 1000 + 500*grade + 50*year;
            cout << name << ":" << position << ",Salary:" << salary << endl;
        }
};

class Teamleader:public Employee
{
    public:
        Teamleader(string &n,string &p,int g,int y):
            Employee(n,p,g,y){}
        virtual void salary()
        {
            int salary = 3000 + 800*grade + 100*year;
            cout << name << ":" << position << ",Salary:" << salary << endl;
        }
};
class Manager:public Employee
{
    public:
        Manager(string &n,string &p,int g,int y):
            Employee(n,p,g,y){}
        virtual void salary()
        {
            int salary = 5000 + 1000*(grade + year);
            cout << name << ":" << position << ",Salary:" << salary << endl;
        }
};

static string positions[3] = {"Employee","Teamleader","Manager"};

int main(){

    int t,grade,year;
    string name,position;
    Employee* jojo = NULL;
    cin >> t;
    while(t > 0)
    {
        t--;
        cin >> name >> position >> grade >> year;
        if(grade < 0 || year < 0)
        {
            cout << "error grade or year." << endl;
            continue;
        }
        if(position == positions[0])
        {
            jojo = new Employee(name,position,grade,year);
        }
        else if(position == positions[1])
        {
            jojo = new Teamleader(name,position,grade,year);
        }
        else if(position == positions[2])
        {
            jojo = new Manager(name,position,grade,year);
        }
        else
        {
            cout << "error position." << endl;
            continue;
        }
        jojo->salary();
    }

    return 0;
}