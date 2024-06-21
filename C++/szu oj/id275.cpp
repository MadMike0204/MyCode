#include <iostream>
using namespace std;

class Node2D
{
    protected:
        string location;
    public:
        Node2D(string location_):
            location(location_){}
};
class Body:public Node2D
{
    protected:
        int maxH;
        int curH;
        int defense;
    public:
        Body(string location_,int mH,int cH,int d):
            Node2D(location_),maxH(mH),curH(cH),defense(d){}
};
class Weapon:public Node2D
{
    protected:
        string wname;
        int damage;
    public:
        Weapon(string location_,string name_,int damage_):
            Node2D(location_),wname(name_),damage(damage_){}
};
class Player:virtual Body,virtual Weapon
{
    protected:
        string name;
    public:
        Player(string location_,string wname_,string name_,
           int damage_,int mH,int cH,int d):
           Body(location_,mH,cH,d),Weapon(location_,wname_,damage_),
           name(name_){}
        void attack(Player &p)
        {
            p.curH -= (damage - p.defense);
            cout << name << " deal " << (damage - p.defense)
                 << " damage to " << p.name << endl;
        }
        int getH()
        {
            return curH;
        }
        string getName()
        {
            return name;
        }
        string getWname()
        {
            return wname;
        }
};
int main(){

    string location,wname,name;
    int mH,dfs,dmg;

    cin >> location
        >> name >> mH >> dfs >> wname >> dmg;
    Player p1(location,wname,name,dmg,mH,mH,dfs);
    cin >> name >> mH >> dfs >> wname >> dmg;
    Player p2(location,wname,name,dmg,mH,mH,dfs);

    while(1)
    {
        p1.attack(p2);
        if(p2.getH() <= 0)
        {
            cout << p1.getName() 
                 << " defeated " << p2.getName()
                 << " by " << p1.getWname() 
                 << " in " << location << endl;
            break;
        }
        else
        {
            cout << p2.getName() << " still have " 
                 << p2.getH() << " health" << endl;
        }
        cout << endl;
        p2.attack(p1);
        if(p1.getH() <= 0)
        {
            cout << p2.getName() 
                 << " defeated " << p1.getName()
                 << " by " << p2.getWname() 
                 << " in " << location << endl;
            break;
        }
        else
        {
            cout << p1.getName() << " still have " 
                 << p1.getH() << " health" << endl;
        }
        cout << endl;
    }

    return 0;
}