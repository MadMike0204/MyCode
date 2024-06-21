#include <iostream>
#include <string>
using namespace std;

static char Type[2][15] = {"undergraduate","postgraduate"};//0本科 1研究生

class Student;
class CL
{
    private:
        string code;
        string name;
        int mark;
        int nn;
    public:
        void initial(string &code_in,string &name_in,int &nn_in,int &mark_in)
        {
            code = code_in;
            name = name_in;
            nn = nn_in;
            mark = mark_in;
        }
        int getMark()
        {
            return mark;
        }
        int getNN()
        {
            return nn;
        }
};
class Student
{
    private:
        string code;
        string name;
        string profession;//专业
        int age;
        int nn_all;//学分
        int course_num;
        int passed_num;
        int grade;//年级
        bool type;
        CL *mycourse;
    public:
        Student(string &code_in,string name_in,int age_in,string profession_in,int grade_in):
                code(code_in),name(name_in),age(age_in),profession(profession_in),grade(grade_in)
        {
            nn_all = 0;
            passed_num = 0;
            type = 0;
        }
        Student(Student &Base)
        {
            code = "2100"+Base.code;
            name = Base.name;
            profession = Base.profession;
            age = Base.age;
            grade = 1;
            type = 1;
            mycourse = Base.mycourse;
            nn_all = Base.nn_all;
            course_num = Base.course_num;
            passed_num = Base.passed_num;
        }
        void record(int n)
        {   
            course_num = n;
            string code_in,name_in;
            int nn_in,mark_in;
            mycourse = new CL[n];
            for(int i=0;i<n;i++)
            {
                cin >> code_in >> name_in >> nn_in >> mark_in;
                mycourse[i].initial(code_in,name_in,nn_in,mark_in);
            }
        }
        void Count()
        {
            for(int i=0;i<course_num;i++)
            {
                if(mycourse[i].getMark() >= 60)
                {
                    nn_all += mycourse[i].getNN();
                    passed_num++;
                }
            }
        }
        void display(char operation)
        {
            cout << code << " " << name << " " << age << " " << profession 
                     << " " << Type[type] << " " << grade;
            if(operation == 'D')
            {
                cout << " "
            }
            else if(operation == 'C' && type == 1)
            {
                cout << " " <<passed_num << " " << nn_all;
            }
            else if(operation == 'C' && type == 0)
            {
                cout << " " << course_num << " " << nn_all;
            }
            cout << endl;
        }
};


int main(){

    int t;
    string code,name,profession,cname,ccode;
    int nn,age,grade,course_num;
    cin >> t;
    while(t > 0)
    {
        cin >> code >> name >> age >> profession >> grade;
        Student jojo(code,name,age,profession,grade);
        cin >> course_num;
        jojo.record(course_num);
        jojo.Count();

        Student Dio(jojo);

        char op1,op2;
        cin >> op1 >> op2;
        jojo.display(op1);
        Dio.display(op2);

        t--;
        jojo.~Student();
        Dio.~Student();
    }

    return 0;
}