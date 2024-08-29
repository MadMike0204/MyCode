#include <iostream>
#include <cstring>
using namespace std;

struct student{
    string name;
    int chinese,math,english;
    int sum;
    int calculate()
    {
        sum = chinese + math + english;
        return sum;
    }
    student()
    {
        chinese = math = english = sum = 0;
    }
};

int main(){

    string name;
    int chinese,math,english;
    int t,max = -1,idx = 0;
    cin >> t;
    student students[t];
    for(int i=0;i<t;i++)
    {
        cin >> students[i].name 
            >> students[i].chinese
            >> students[i].math
            >> students[i].english;
        if(students[i].calculate() > max)
        {
            max = students[i].calculate();
            idx = i;
        }
    }
    cout << students[idx].name << " "
         << students[idx].chinese << " "
         << students[idx].math << " "
         << students[idx].english << endl;

    return 0;
}