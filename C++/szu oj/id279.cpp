#include <iostream>
using namespace std;

class CVehicle
{
    protected:
        int max_speed;
        int speed;
        int weight;
    public: 
        CVehicle(int a,int b,int c):
            max_speed(a),speed(b),weight(c){}
        void display()
        {
            cout << "Vehicle:" << endl
                 << "max_speed:" << max_speed << endl
                 << "speed:" << speed << endl
                 << "weight:" << weight << endl;
        }
};
class CBicycle:public CVehicle
{
    protected:
        int height;
    public:
        CBicycle(int a,int b,int c,int d):
            CVehicle(a,b,c),height(d){}
        void display()
        {
            cout << "Bicycle:" << endl
                 << "max_speed:" << max_speed << endl
                 << "speed:" << speed << endl
                 << "weight:" << weight << endl
                 << "height:" << height << endl;
        }
};  
class CMotocar:public CVehicle
{
    protected:
        int seat_num;
    public:
        CMotocar(int a,int b,int c,int d):
            CVehicle(a,b,c),seat_num(d){}
        void display()
        {
            cout << "Motocar:" << endl
                 << "max_speed:" << max_speed << endl
                 << "speed:" << speed << endl
                 << "weight:" << weight << endl
                 << "seat_num:" << seat_num << endl;
        }
};  

class CMotocycle:public CMotocar,public CBicycle
{
    public:
        CMotocycle(int a,int b,int c,int d,int e):
            CBicycle(a,b,c,d),CMotocar(a,b,c,e){}
        void display()
        {
            cout << "Motocycle:" << endl
                 << "max_speed:" << CBicycle::max_speed << endl
                 << "speed:" << CBicycle::speed << endl
                 << "weight:" << CBicycle::weight << endl
                 << "height:" << CBicycle::height << endl
                 << "seat_num:" << CMotocar::seat_num << endl;
        }
};  

int main(){

    int maxspd,spd,weight,height,seat;
    cin >> maxspd >> spd >> weight >> height >> seat;
    CVehicle V1(maxspd,spd,weight);
    V1.display();
    cout << endl;
    CBicycle V2(maxspd,spd,weight,height);
    V2.display();
    cout << endl;
    CMotocar V3(maxspd,spd,weight,seat);
    V3.display();
    cout << endl;
    CMotocycle V4(maxspd,spd,weight,height,seat);
    V4.display();

    return 0;
}