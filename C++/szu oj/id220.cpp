#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
static double PRECISION = 0.0001;

class Student
{
    protected:
        string id;
        string name;
    public:
        Student(string i,string n):
            id(i),name(n){}
        virtual void display(float line){}
        virtual bool isObserve(){return 0;}
};
class GroupA:public Student
{
    private:
        int grade1;
        int grade2;
    public:
        GroupA(string i,string n,int g1,int g2):
            Student(i,n),grade1(g1),grade2(g2){}
        virtual bool isObserve(float line)
        {
            if((grade1+grade2)/2.0 > line || fabs((grade1+grade2)/2.0 - line) < PRECISION)
            {
                return 1;
            }
            return 0;
        }
        virtual void display(float line)
        {
            if(isObserve(line))
            {
                cout << id << " " << name << endl;
            }
            return;
        }

};
class GroupB:public Student
{
    private:
        int grade1;
        int grade2;
        char performance;
    public:
        GroupB(string i,string n,int g1,int g2,char p):
            Student(i,n),grade1(g1),grade2(g2),performance(p){}
        virtual bool isObserve(float line)
        {
            if(performance == 'A' && ((grade1+grade2)/2.0 > line*0.7 || fabs((grade1+grade2)/2.0 - 0.7*line) < PRECISION))
            {
                return 1;
            }
            return 0;
        }
        virtual void display(float line)
        {
            if(isObserve(line))
            {
                cout << id << " " << name << endl;
            }
            return;
        }
};
class GroupC:public Student
{
    private:
        int grade1,grade2,grade3,grade4,grade5;
    public:
        GroupC(string i,string n,int g1,int g2,int g3,int g4,int g5):
            Student(i,n),grade1(g1),grade2(g2),grade3(g3),grade4(g4),grade5(g5){}
        virtual bool isObserve(float line)
        {
            if((grade1+grade2+grade3+grade4+grade5)/5.0 > line*0.9 
              || fabs((grade1+grade2+grade3+grade4+grade5)/5.0 - 0.9*line) < PRECISION)
            {
                return 1;
            }
            return 0;
        }
        virtual void display(float line)
        {
            if(isObserve(line))
            {
                cout << id << " " << name << endl;
            }
            return;
        }
};

int main(){

    const int Size = 50;
    string num, name;
    int i, ty, s1, s2, s3, s4, s5;
    char gs;
    Student *pS[Size];
    int count = 0;
    float line = -999;
    for (i = 0; i < Size; i++)
    {
        cin >> ty;
        if (ty == 0)
            break;
        cin >> num >> name >> s1 >> s2;
        switch (ty)
        {
        case 1:
            pS[count++] = new GroupA(num, name, s1, s2);
            if((s1+s2)/2 > line)
                line = (s1+s2)/2.0;
            break;
        case 2:
            cin >> gs;
            pS[count++] = new GroupB(num, name, s1, s2, gs);
            if((s1+s2)/2 > line)
                line = (s1+s2)/2.0;
            break;
        case 3:
            cin >> s3 >> s4 >> s5;
            pS[count++] = new GroupC(num, name, s1, s2, s3, s4, s5);
            break;
        }
    }
    for (i = 0; i < count; i++)
    {
        pS[i]->display(line);
        delete pS[i];
    }

    return 0;
}