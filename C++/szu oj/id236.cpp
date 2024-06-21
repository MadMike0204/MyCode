#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Person
{
    protected:
        string name;
        int age;
    public:
        Person(string name_,int age_):
            name(name_),age(age_){}
        void display()
        {
            cout << name << " " << age << endl;
        }
};
class Student:public Person
{
    protected:
        float continuous_grade;
        float exam_grade;
        float full_grade;
    public:
        Student(string name_,int age_,float cg,float eg):
            Person(name_,age_),continuous_grade(cg),exam_grade(eg){}
        void display()
        {
            cout << name << " " << age << " " << fixed << setprecision(2) << full_grade << endl;
        }
        float getFG()
        {
            full_grade = continuous_grade * 0.4 + exam_grade * 0.6;
            return full_grade;
        }
};
class Teacher:public Person
{
    protected:
        int enrolled_number;
        float average_grade;
        vector<Student*> students;
    public:
        Teacher(string name_,int age_,int en):
            Person(name_,age_),enrolled_number(en){}
        void display()
        {
            cout << name << " " << age << " " 
                 << enrolled_number << " " << fixed << setprecision(2) << average_grade << endl;
        }
        void addStudent(Student *p)
        {
            students.push_back(p);
        }
        void getAG()
        {
            float sum = 0;
            for(Student* student:students)
            {
                sum += student->getFG();
            }
            average_grade = sum / enrolled_number;
        }
        Student* getStudent(int idx)
        {
            return students[idx];
        }
};

int main(){

    int age,number;
    string name;
    cin >> name >> age >> number;
    Teacher jostar(name,age,number);
    
    float cg,eg;
    Student* jojo;
    for(int i=0;i<number;i++)
    {
        cin >> name >> age >> cg >> eg;
        jojo = new Student(name,age,cg,eg);
        jojo->getFG();
        jostar.addStudent(jojo);
    }
    jostar.getAG();
    jostar.display();
    for(int i=0;i<number;i++)
    {
        jojo = jostar.getStudent(i);
        jojo->display();
    }

    return 0;
}