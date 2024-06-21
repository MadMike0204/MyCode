#include <iostream>
using namespace std;

struct Stu
{
    string id;
    string name;
    int g1;
    int g2;
    int g3;
};

Stu newStudent(int n)
{
    Stu Stt;
    cin >> Stt.id >> Stt.name >> Stt.g1 >> Stt.g2 >> Stt.g3;
    return Stt;
}

int addHash(Stu (&jojo)[],int t)
{
    int num,the=0,last=-1;
    for(int i=0;i<t;i++)
    {
        the = jojo[i].g1 + jojo[i].g2 + jojo[i].g3;
        if(the > last)
        {
            last = the;
            num = i;
        }
    }
    return num;
}

int main(){

    int t;
    cin >> t;
    Stu jojo[t];
    for(int i=0;i<t;i++)
    {
        jojo[i] = newStudent(i);
    }
    int x = addHash(jojo,t);
    int grade = jojo[x].g1 + jojo[x].g2 +jojo[x].g3;
    cout << jojo[x].name << " " <<jojo[x].id << " " << grade << endl;
    return 0;
}