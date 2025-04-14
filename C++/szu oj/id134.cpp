#include<iostream>
#include<cstring>
using namespace std;
class Student
{
public:
    Student(char *pname)
    {
        cout << "Constructing " << pname << endl;
        name = new char[strlen(pname) + 1];
        if (name != NULL)
            strcpy(name, pname);
    }
    Student(Student &s);
    ~Student();
 
protected:
    char *name;
};
Student::Student(Student &s){
    name = new char[strlen(s.name)+1];
    strcpy(name,s.name);
    cout << "Copying of " << name << endl;
}
Student::~Student(){
    cout << "Destructing " << name << endl;
    if(name)
        delete name;
    
}
int main()
{
    char name[10];
    cin>>name;
    Student s1(name);
    Student s2 = s1;
}