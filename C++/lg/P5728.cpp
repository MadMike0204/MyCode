#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Student{
    int chinese;
    int math;
    int english;
};
int main(){

    int N,a,b,c,count=0;
    bool flag;
    cin >> N;
    vector<Student> Students;
    for(int i=0;i<N;i++)
    {
        cin >> a >> b >> c;
        Student m{a,b,c};
        Students.push_back(m);
        for(int j=0;j<i;j++)
        {
            flag = 0;
            if((int)fabs(Students[i].chinese-Students[j].chinese) <= 5)
                if((int)fabs(Students[i].math-Students[j].math) <= 5)
                    if((int)fabs(Students[i].english-Students[j].english) <= 5)
                    {
                        int sum1 = Students[i].chinese+Students[i].english+Students[i].math;
                        int sum2 = Students[j].chinese+Students[j].english+Students[j].math;
                        if((int)fabs(sum1-sum2) <= 10)
                            flag = 1;
                    }
            if(flag)
                count++;
        }
    }
    cout << count << endl;

    return 0;
}