#include<iostream>
#include<vector>
using namespace std;

struct StudentInfomation{
    string name;
    short age;
    int grade;
};

bool swapStudent(StudentInfomation &stu1,StudentInfomation &stu2){
    StudentInfomation temp = stu1;
    stu1 = stu2;
    stu2 = temp;
    return 1;
}


void sortStudents(vector<StudentInfomation> &students) {
    int n = students.size();
    
    for (int i = 1; i < n; i++) {
        StudentInfomation temp = students[i];
        int j = i - 1;
        while (j >= 0) {
            if (students[j].grade > temp.grade) {
                students[j + 1] = students[j];
            }
            else if (students[j].grade == temp.grade) {
                if (students[j].name > temp.name) {
                    students[j + 1] = students[j];
                }
                else if (students[j].name == temp.name) {
                    if (students[j].age > temp.age) {
                        students[j + 1] = students[j];
                    }
                    else {
                        break; // 已排序
                    }
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
            j--;
        }
        students[j + 1] = temp;
    }
}

void printStudents(vector<StudentInfomation> &students){
    int length = students.size();
    for(int i=0;i<length;i++){
        cout << students[i].name << " "
             << students[i].age << " "
             << students[i].grade << endl;
    }
}

int main(){

    int n;
    cin >> n;
    vector<StudentInfomation> students;
    while(n--){
        string name;
        short age;
        int grade;
        cin >> name >> age >> grade;
        students.push_back({name,age,grade});
    }
    sortStudents(students);
    printStudents(students);

    return 0;
}