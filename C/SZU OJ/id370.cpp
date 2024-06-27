#include <iostream>
using namespace std;

class Member
{
    protected:
        int id,bonus;
        string name;
    public:
        virtual void Add(int sum)
        {
            bonus += sum;
        }
        virtual int Exchange(int sum)
        {
            int k = sum/100;
            bonus -= k * 100;
            return (sum/100);
        }
        virtual void Print()
        {
            cout << "普通会员" << id << "--" << name << "--" << bonus << endl;
        }
        Member(string n,int i,int bo=0):
            id(i),bonus(bo),name(n){}
};
class VipMember:public Member
{
    private:
        int addrate,exrate;
    public:
        virtual void Add(int sum)
        {
            bonus += (sum*addrate);
        }
        virtual int Exchange(int sum)
        {
            int k = sum/exrate;
            bonus -= k * exrate;
            return k;
        }
        virtual void Print()
        {
            cout << "贵宾会员" << id << "--" << name << "--" << bonus << endl;
        }
        VipMember(string n,int i,int ar,int er,int bo=0):
            Member(n,i,bo),addrate(ar),exrate(er){}
};

int main(){

    int id,bonus,b,c;
    string name;
    cin >> id >> name >> bonus;
    Member* jojo = new Member(name,id,bonus);
    cin >> b >> c;
    jojo->Add(b);
    jojo->Exchange(c);
    jojo->Print();
    delete jojo;

    cin >> id >> name >> bonus >> b >> c;
    Member* jostar = new VipMember(name,id,b,c,bonus);
    cin >> b >> c;
    jostar->Add(b);
    jostar->Exchange(c);
    jostar->Print();

    return 0;
}