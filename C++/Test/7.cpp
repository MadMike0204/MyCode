#include <iostream>
using namespace std;

struct Man
{ 
    string name;
    int id;
    double salary;
};

Man newMan(string name,int id,double salary)
{
    Man newnew = {name,id,salary};
    return newnew;
}

void PPP(Man &MM)
{

}

int main()
{ 
    Man Cobe = {"Kobe Bryant",114514,1919810};
    Man Helicopter = newMan("Cobe",114514,1919810);   
    cout << Helicopter.name << endl << Cobe.name << endl;

    return 0;
}
