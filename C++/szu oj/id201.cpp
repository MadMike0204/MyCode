#include <iostream>
#include <string>
using namespace std;
class Student {
protected:
    string name;   
    string stuId;  

public:
    Student(string id, string n) : stuId(id), name(n) {}
    

    virtual int tuition() {
        return 2000; 
    }
    
    virtual void display() {
        cout << name << " " << stuId << " " << tuition() << endl;
    }
};


class Graduate : public Student {
private:
    string mentor; 

public:
    Graduate(string id, string n, string m) : Student(id, n), mentor(m) {}
    
    int tuition() override {
        return 1000; 
    }
    
    void display() override {
        cout << name << " " << stuId << " " << mentor << " " << tuition() << endl;
    }
};

int main() {
    int t;
    cin >> t; 
    
    while (t--) {
        char type;
        cin >> type;
        
        if (type == 'G') {
            string id, name, mentor;
            cin >> id >> name >> mentor;
            Graduate g(id, name, mentor);
            g.display();
        } 
        else if (type == 'S') {
            string id, name;
            cin >> id >> name;
            Student s(id, name);
            s.display();
        }
    }
    
    return 0;
}
