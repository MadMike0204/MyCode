#include <iostream>
using namespace std;

class Fnt
{
    protected:
        int id,power;
    public:
        Fnt(int i,int p):
            id(i),power(p){}
        virtual void Print()
        {
            cout << "编号" << id << "--" << "功率" << power << 'W' << endl;
        }
};

class Fan:public virtual Fnt
{
    protected:
        int mode,wind;
    public:
        Fan(int i,int p,int m,int w):
            Fnt(mode,wind),mode(m),wind(w){}
        void Mode_Switch(int m)
        {
            mode = m;
        }
        void Wind_Switch(int w)
        {
            wind = w;
        }
};
class Humidifier:public virtual Fnt
{
    protected:
        double cur_v,max_v;
    public:
        Humidifier(int i,int p,int cur,int max):
            Fnt(i,p),cur_v(cur),max_v(max){}
        int Warning()
        {
            if(cur_v < max_v * 0.1)
            {
                return 3;
            }
            else if(cur_v < max_v *0.5)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
};

class HumidFan:public Humidifier,public Fan
{
    private:
        int smod;
    public:
        HumidFan(int i,int p,int cur,int max,int mode,int wind,int s):
            Fnt(i,p),Humidifier(i,p,cur,max),Fan(i,p,mode,wind),smod(s){}
        void Smod_switch(int s)
        {
            if(s)
            {
                if(s == 1)
                {
                    Mode_Switch(0);
                    Wind_Switch(s);
                }
                else if(s >=2)
                {
                    Mode_Switch(1);
                    Wind_Switch(s);
                }
            }
            smod = s;
        }
        virtual void Print()
        {
            cout << "加湿风扇--档位" << smod << endl
                 << "编号" << id << "--" << "功率" << power << 'W' << endl;
            if(!mode)
                cout << "定向吹风--风力";
            else 
                cout << "旋转吹风--风力";
            cout << wind << "级" << endl
                 << "实际水容量" << cur_v <<"升--";
            int Wcode = Warning();
            if(Wcode == 1)
            {
                cout << "水量正常" << endl;
            }
            else if(Wcode == 2)
            {
                cout << "水量偏低" << endl;
            }
            else if(Wcode == 3)
            {
                cout << "水量不足" << endl;
            }
        }
};

int main(){

    int t,opcode;
    cin >> t;
    int id,power,mode,wind,max,cur,smod;
    while(t--)
    {
        cin >> id >> power >> mode >> wind >> cur >> max >> smod;
        HumidFan HF(id,power,cur,max,mode,wind,smod);
        cin >> opcode;
        HF.Smod_switch(opcode);
        HF.Print();
    }

    return 0;
}