#include <iostream>
using namespace std;

class CClock
{
    private:
        int hour,minute,second;
        void Update()
        {
            int temp;
            if(second >= 60)
            {
                temp = second/60;
                second %= 60;
                minute += temp;
            }
            if(minute >= 60)
            {
                temp = minute/60;
                minute %= 60;
                hour += temp;
            }
            if(hour >= 24)
            {
                hour %= 24;
            }
        }
    public:
        CClock(int h=0,int m=0,int s=0):
            hour(h),minute(m),second(s){}
        CClock& operator + (CClock& jo)
        {
            this->hour += jo.hour;
            this->minute += jo.minute;
            this->second += jo.second;
            this->Update();
            return *this;
        }
        friend ostream& operator << (ostream& stream,const CClock &t);
};

ostream& operator << (ostream& stream,const CClock &t)
{
    cout << t.hour << " " << t.minute << " " << t.second << endl;
    return stream;
}

class CRMB
{
    private:
        int yuan,fen,jiao;
        void Update()
        {
            int temp;
            if(fen >= 10)
            {
                temp = fen/10;
                fen %= 10;
                jiao += temp;
            }
            if(jiao >= 10)
            {
                temp = jiao/10;
                jiao %= 10;
                yuan += temp;
            }
        }
    public:
        CRMB(int y=0,int j=0,int f=0):
            yuan(y),jiao(j),fen(f){}
        CRMB& operator + (CRMB& jo)
        {
            this->yuan += jo.yuan;
            this->jiao += jo.jiao;
            this->fen += jo.fen;
            this->Update();
            return *this;
        }
        friend ostream& operator << (ostream& stream,const CRMB &t);
};

ostream& operator << (ostream& stream,const CRMB &t)
{
    cout << t.yuan << " " << t.jiao << " " << t.fen << endl;
    return stream;
}

template<class T>
void ADD(T &o1,T &o2)
{
    T result = o1 + o2;
    cout << result;
    return;
}

int main(){

    int a,b,c;
    cin >> a >> b >> c;
    CClock c1(a,b,c);
    cin >> a >> b >> c;
    CClock c2(a,b,c);
    ADD(c1,c2);

    cin >> a >> b >> c;
    CRMB r1(a,b,c);
    cin >> a >> b >> c;
    CRMB r2(a,b,c);
    ADD(r1,r2);
    
    return 0;
}