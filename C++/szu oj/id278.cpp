#include <iostream>
using namespace std;

class CPeople {
protected:
    string name;
    string sex;
    int age;
public:
    CPeople(string n, string s, int a) : name(n), sex(s), age(a) {}
    virtual void print() {
        cout << "Name: " << name << endl;
        cout << "Sex: " << sex << endl;
        cout << "Age: " << age << endl;
    }
};

class CStudent : public virtual CPeople {
protected:
    string id;
    double grade;
public:
    CStudent(string n, string s, int a, string i, double g) :
        CPeople(n, s, a), id(i), grade(g) {}
    virtual void print() {
        CPeople::print();
        cout << "No.: " << id << endl;
        cout << "Score: " << grade << endl;
    }
};

class CTeacher : public virtual CPeople {
protected:
    string job;
    string section;
public:
    CTeacher(string n, string s, int a, string j, string sec) :
        CPeople(n, s, a), job(j), section(sec) {}
    virtual void print() {
        CPeople::print();
        cout << "Position: " << job << endl;
        cout << "Department: " << section << endl;
    }
};

class CGradOnWork : public CStudent, public CTeacher {
protected:
    string direction;
    string mentor;
public:
    CGradOnWork(string n, string s, int a,
                string j, string sec,
                string i, double g,
                string dir, string me) :
        CPeople(n, s, a), CStudent(n, s, a, i, g),
        CTeacher(n, s, a, j, sec),
        direction(dir), mentor(me) {}
    void print() {
        CPeople::print();
        cout << "No.: " << id << endl;
        cout << "Score: " << grade << endl;
        cout << "Position: " << job << endl;
        cout << "Department: " << section << endl;
        cout << "Direction: " << direction << endl;
        cout << "Tutor: " << mentor << endl;
    }
};

int main() {
    string name, sex, id, job, section, mentor, direction;
    int age;
    double grade;

    cin >> name >> sex >> age;
    CPeople p1(name, sex, age);

    cin >> id >> grade;
    CStudent p2(name, sex, age, id, grade);

    cin >> job >> section;
    CTeacher p3(name, sex, age, job, section);

    cin >> direction >> mentor;
    CGradOnWork p4(name, sex, age, job, section, id, grade, direction, mentor);
    cout << "People:" << endl;
    p1.print();
    cout << endl;
    cout << "Student:" << endl;
    p2.print();
    cout << endl;
    cout << "Teacher:" << endl;
    p3.print();
    cout << endl;
    cout << "GradOnWork:" << endl;
    p4.print();

    return 0;
}
