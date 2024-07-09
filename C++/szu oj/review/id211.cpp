#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class CPerson
{
    protected:
        string name;
        string tel;
    public:
        CPerson(string n = "NONE",string t = "NONE"):name(n),tel(t){}
};
class NP:public CPerson
{
    private:
        int Atime[12];
    public:
        NP(string n = "NONE",string t = "NONE"):CPerson(n,t)
        {
            for(int i=0;i<12;i++)
            {
                cin >> Atime[i];
            }
        }
        void Check()
        {
            int count = 0;
            for(int i=0;i<12;i++)
            {
                if(Atime[i] / 60)
                {
                    count++;
                }
            }
            if(count >= 10)
            {
                cout << name << "达到学时要求可以预约！电话" << tel;
            }
            else 
            {
                cout << name << "未达到学时要求不能预约！电话" << tel;
            }
            cout << endl;
        }
};
class VIP:public CPerson
{
    private:
        int Atime[12];
        int Btime[12];
    public:
        VIP(string n = "NONE",string t = "NONE"):CPerson(n,t)
        {
            for(int i=0;i<12;i++)
            {
                cin >> Atime[i];
            }
            for(int i=0;i<12;i++)
            {
                cin >> Btime[i];
            }
        }
        void Check()
        {
            int count = 0;
            for(int i=0;i<12;i++)
            {
                if(Atime[i] / 60)
                {
                    count++;
                }
                if(Btime[i] / 120)
                {
                    count += 2;
                }
                else if(Btime[i] / 60)
                {
                    count++;
                }

            }
            if(count >= 10)
            {
                cout << name << "达到学时要求可以预约！电话" << tel;
            }
            else 
            {
                cout << name << "未达到学时要求不能预约！电话" << tel;
            }
            cout << endl;
        }
};
int main(){

    int t;
    char type;
    string name,tel;
    cin >> t;
    while(t--)
    {
        cin >> type >> name >> tel;
        if(type == 'F')
        {
            NP jojo(name,tel);
            jojo.Check();
        }
        else if(type == 'V')
        {
            VIP jojo(name,tel);
            jojo.Check();
        }
    }

    return 0;
}