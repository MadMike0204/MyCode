#include <iostream>
using namespace std;

class Animal{
    protected:
       int weight;
    public:
    Animal(int w):weight(w){} 
    void print(){
        cout << "Animal:" << endl;
        cout << "weight:" << weight << endl;
    }
};
class Horse: public Animal{
    protected:
        int Distance;
    public:
    Horse(int w,int d):Animal(w),Distance(d){}
    void print(){
        cout << "Horse:" << endl;
        cout << "weight:" << weight<< endl
             << "distance:" << Distance << endl;
    }
};  
class Bird: public Animal{
    protected:
        int Height;
    public:
    Bird(int w,int h):Animal(w),Height(h){}
    void print(){
        cout << "Bird:" << endl;
        cout << "weight:" << weight<< endl
             << "Height:" << Height << endl;
    }
};
class Pegasus: public Horse,public Bird,public Animal{
    private:
        bool state;
    public:
        Pegasus(int w,int d,int h,bool s):Animal(w),Horse(w,d),Bird(w,h),state(s){}
        void print(){
            cout << "Pegasus:" << endl;
            cout << "weight:" << Horse::weight<< endl
                 << "distance:" << Distance<< endl
                 << "Height:" << Height << endl;
            cout << "In the air?" << endl;
            if(state)
                cout << "true" << endl;
            else
                cout << "false" << endl;
            cout << "On land?" << endl;
            if(!state)
                cout << "true" << endl;     
            else
                cout << "false" << endl;
        }
};

int main(){

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    Pegasus p(a,b,c,d);
    Horse ee = p;
    Bird eee = p;
    Animal eeee(a);
    eeee.print();
    cout << endl;
    ee.print();
    cout << endl;
    eee.print();
    cout << endl;
    p.print();

    return 0;
}