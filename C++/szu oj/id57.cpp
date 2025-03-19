#include<iostream>
using namespace std;

struct Person{
    string name;
    int years;
    int salary;
    Person(string n = "",int y = 0,int s = 0):name(n),years(y),salary(s){}
    void setPerson(string n,int y,int s){
        name = n;
        years = y;
        salary = s;
    }
    void salaryAdjustment(){
        if(years > 30){
            salary += 100;
        }
    }
    void printPerson(){
        cout << name << " " << years << " " << salary << endl;
    }
};

int main(){

    Person* persons = new Person[5];
    string n;
    int y,s;
    for(int i=0;i<5;i++){
        cin >> n >> y >> s;
        persons[i].setPerson(n,y,s);
    }
    cout << "原始工资" << endl << "姓名 年限 工资" << endl;
    for(int i=0;i<5;i++){
        persons[i].printPerson();
    }
    cout << "加薪后工资" << endl << "姓名 年限 工资" << endl;
    for(int i=0;i<5;i++){
        persons[i].salaryAdjustment();
        persons[i].printPerson();
    }
    return 0;
}