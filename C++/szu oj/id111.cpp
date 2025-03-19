#include <iostream>
#include <vector>
using namespace std;

class Employee{
    private:
        string name;
        string jobNumber;
        string section;
        string job;
        string gender;
        string telephoneNumber;
    public:
        void setName(string name){
            this->name = name;
        }
        void setJobNumber(string jobNumber){
            this->jobNumber = jobNumber;
        }
        void setSection(string section){
            this->section = section;
        }
        void setGender(string gender){
            this->gender = gender;
        }
        void setPhoneNumber(string phoneNumber){
            this->telephoneNumber = phoneNumber;
        }
        void setJob(string job){
            this->job = job;
        }
        string getName(){
            return name;
        }
        string getJobNumber(){
            return jobNumber;
        }
        string getSection(){
            return section;
        }
        string getJob(){
            return job;
        }
        string getGender(){
            return gender;
        }
        string getTelephoneNumber(){
            return telephoneNumber;
        }
};

int main(){

    int t;
    cin >> t;
    vector<Employee> employees(t);

    for (int i = 0; i < t; ++i) {
        string name, jobNumber, section, job, gender, telephoneNumber;
        cin >> name >> jobNumber >> section >> job >> gender >> telephoneNumber;

        employees[i].setName(name);
        employees[i].setJobNumber(jobNumber);
        employees[i].setJob(job);
        employees[i].setSection(section);
        employees[i].setGender(gender);
        employees[i].setPhoneNumber(telephoneNumber);
    }

    for (int i = 0; i < t; ++i) {
        cout << employees[i].getName() << " ";
        cout << employees[i].getJobNumber() << " ";
        cout << employees[i].getSection() << " ";
        cout << employees[i].getJob() << " ";
        cout << employees[i].getGender() << " ";
        cout << employees[i].getTelephoneNumber() << endl;
    }

    return 0;
}