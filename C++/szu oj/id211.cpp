#include <iostream>
#include "jobapi.h"
using namespace std;

class CPerson
{   
    protected:
        string name;
        string telnum;
    public:
        CPerson(string &name_in,string &telnum_in):name(name_in),telnum(telnum_in){}
};
class DefaultP:public CPerson
{
    protected:
        int Atime[12];
    public:
        DefaultP(string &name_in,string &telnum_in,int time[12]):CPerson(name_in,telnum_in)
        {
            for(int i=0;i<12;i++)
            {
                Atime[i] = time[i];
            }
        }
        void check()
        {
            int hour = 0;
            for(int i=0;i<12;i++)
            {
                if((hour/60) > 0 && (hour%60)<2)
                    hour++;
            }
            if(hour>=10)
            {
                cout << name << "达到学时要求可以预约！电话" << telnum << endl;
            }
            else
            {
                cout << name << "未达到学时要求不能预约！电话" << telnum << endl;
            }
        }
};
class VIP:public DefaultP
{
    protected: 
        int Btime[12];
    public:
        VIP(string &name_in,string &telnum_in,int atime[12],int btime[12]):
            DefaultP(name_in,telnum_in,atime)
        {
            for(int i=0;i<12;i++)
            {
                Btime[i] = btime[i];
            }
        }
        void check()
        {
            int hour = 0;
            for(int i=0;i<12;i++)
            {
                if((Atime[i]/60) > 0)
                    hour++;
            }
            for(int i=0;i<12;i++)
            {
                if((Btime[i]/60) > 0)
                {
                    hour++;
                    if((Btime[i]/60) > 1)
                    {
                        hour++;
                    }
                }
            }
            if(hour>=10)
            {
                cout << name << "达到学时要求可以预约！电话" << telnum << endl;
            }
            else
            {
                cout << name << "未达到学时要求不能预约！电话" << telnum << endl;
            }
        }
};
int main(){

    int t;
    string name,telnum;
    int time[12];
    char type;
    cin >> t;
    while(t>0)
    {   
        cin >> type >> name >> telnum;
        for(int i=0;i<12;i++)
        {
            cin >> time[i];
        }
        if(type == 'F')
        {
            DefaultP jojo(name,telnum,time);
            jojo.check();
        }
        else
        {
            int time2[12];
            for(int i=0;i<12;i++)
            {
                cin >> time2[i];
            }
            VIP jojo(name,telnum,time,time2);
            jojo.check();
        }
        t--;
    }

    return 0;
}