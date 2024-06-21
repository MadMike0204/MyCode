#include <iostream>
using namespace std;

class Person
{
    protected:
        string name;
        int age;
    public:
        Person(string &name_in,int age_in):name(name_in),age(age_in){}
        void display()
        {
            cout << name << " " << age << " ";
        }
};
class skipP:public Person
{
    protected:
        int grade_exam;
        char grade_weight;
    public:
        skipP(string &name_in,int age_in,int grade_exam_in):Person(name_in,age_in),grade_exam(grade_exam_in){}
        char getW()
        {
            switch(grade_exam)
            {
                case 0 ... 59: 
                    grade_weight = 'F';
                    break;
                case 60 ...65:
                    grade_weight = 'D';
                    break;
                case 66 ...75:
                    grade_weight = 'C';
                    break;
                case 76 ...85:
                    grade_weight = 'B';
                    break;
                case 86 ... 100:
                    grade_weight = 'A';
            }
            return grade_weight;
        }
        
};
class none_skipP:public Person
{
    protected:  
        int grade_continuous;
        int grade_exam;
        char grade_weight;
    public:
        none_skipP(string &name_in,int age_in,int grade_exam_in,int grade_c):
            Person(name_in,age_in),grade_exam(grade_exam_in),grade_continuous(grade_c){}
        char getW()
        {
            int all = 0.6 * grade_exam + 0.4 * grade_continuous;
            switch(all)
            {
                case 0 ... 59: 
                    grade_weight = 'F';
                    break;
                case 60 ...65:
                    grade_weight = 'D';
                    break;
                case 66 ...75:
                    grade_weight = 'C';
                    break;
                case 76 ...85:
                    grade_weight = 'B';
                    break;
                case 86 ... 100:
                    grade_weight = 'A';
            }
            return grade_weight;
        }
};

int main(){

    int t,grade1,grade2,age;
    cin >> t;
    string name;
    char type;
    while(t>0)
    {
        cin >> type;
        if(type == 'R')
        {
            cin >> name >> age >> grade1 >> grade2;
            none_skipP jostar(name,age,grade1,grade2);
            jostar.display();
            cout << jostar.getW() << endl;
        }
        else
        {
            cin >> name >> age >> grade1;
            skipP jostar(name,age,grade1);
            jostar.display();
            cout << jostar.getW() << endl;
        }
        t--;
    }

    return 0;
}