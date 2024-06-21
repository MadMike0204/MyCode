#include <iostream>
#include <vector>

using namespace std;

class Student
{
    friend int Get_Count();
    private:
        int id;
        int grade;
        static int count;
    public:
        Student()
        {
            Student::count++;
        }
        void Set(int id_in,int grade_in)
        {
            id = id_in;
            grade = grade_in;
        }
        void Print_Counts()
        {
            cout << Student::count << endl;
        }
        void Print_self()
        {
            cout << id << " ";
            if(grade == 0)
            {
                cout << "Fail" << endl;
            }
            else
            {
                cout << "Pass" << endl;
            }
        }
        
};

int Get_Count()
{
    return Student::count;
}

int Student::count = 0;

int main(){
    int N,num,temp,grade,id;
    cin >> N;
    vector<Student> vStudents;
    while(N > 0)
    {
        cin >> num;
        for(int i=0;i<num;i++)
        {
            cin >> temp;
            Student newStudent;
            if(temp == 0)
            {
                newStudent.Set(id+1,grade);
                id++;
            }
            else
            {
                cin >> grade;
                newStudent.Set(temp,grade);
                id = temp;
            }
            vStudents.push_back(newStudent);
        }
        N--;
    }
    cout << Get_Count() << " Students" << endl;
    for(int i=0;i<Get_Count();i++)
    {
        vStudents[i].Print_self();
    }
    return 0;
}