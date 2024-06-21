#include <iostream>
#include <vector>
using namespace std;

class Student{
    private:
        int id;
        int score;
        static int maxscore;
        static int maxid;
    public:
        Student(int id_in,int score_in):id(id_in),score(score_in){}
        Student()
        {
            id = 0;
            score = 0;
        }
        void Set(int id_in,int score_in)
        {
            id = id_in;
            score = score_in;
        }
        static void findMax(Student &stu)
        {
            if(stu.score > maxscore)
            {
                Student::maxscore = stu.score;
                Student::maxid = stu.id;
            }
        }
        static int getMaxScore()
        {
            return maxscore;
        }
        static int getMaxId()
        {
            return maxid;
        }
};

int Student::maxscore = 0;
int Student::maxid = 0;

int main(){

    int n,id,score;
    cin >> n;
    Student students[n];
    for(int i=0;i<n;i++)
    {
        cin >> id >> score;
        students[i].Set(id,score);
        Student::findMax(students[i]);
    }
    cout << Student::getMaxId() << "--" << Student::getMaxScore() << endl;
    return 0;
}