#include<iostream>
using namespace std;

class Player{
    protected:
        string name;
        int height;
        int weight;
    public:
        Player(string n,int h,int w):
            name(n),height(h),weight(w){}
        void display(){
            cout << "Player:" << endl;
            cout << "name:" << name << endl
                 << "height:" << height << endl
                 << "weight:"  << weight << endl;
        }
};
class MVP: public virtual Player{
    protected:
        int MVPy;
    public: 
        MVP(string n,int h,int w,int y):
            Player(n,h,w),MVPy(y){}
        void display(){
            cout << "MVP:" << endl;
            cout << "name:" << name << endl
                 << "height:" << height << endl
                 << "weight:"  << weight << endl
                 << "reward:win the MVP reward in " << MVPy << endl;
        }
};
class DPOY: public virtual Player{
    protected:
        int Dy;
    public: 
    DPOY(string n,int h,int w,int y):
            Player(n,h,w),Dy(y){}
        void display(){
            cout << "DPOY:" << endl;
            cout << "name:" << name << endl
                 << "height:" << height << endl
                 << "weight:"  << weight << endl
                 << "reward:win the DPOY reward in " << Dy << endl;
        }
};
class HOF: public virtual Player,public MVP,public DPOY{
    public: 
    HOF(string n,int h,int w,int my,int dy):
            Player(n,h,w),MVP(n,h,w,my),
            DPOY(n,h,w,dy){}
        void display(){
            cout << "Hall of fame:" << endl;
            cout << "name:" << name << endl
                 << "height:" << height << endl
                 << "weight:"  << weight << endl
                 << "reward1:win the MVP reward in " << MVPy << endl
                 << "reward2:win the DPOY reward in " << Dy << endl;
        }
};

int main(){

    string name;
    int height,weight;
    int y1,y2;

    cin >> name >> height >> weight;
    cin >> y1 >> y2;

    HOF h1(name,height,weight,y1,y2);
    Player a1 = h1;
    MVP a2 = h1;
    DPOY a3 = h1;
    a1.display();
    cout << endl;
    a2.display();
    cout << endl;
    a3.display();
    cout << endl;
    h1.display();
    cout << endl;


    return 0;
}