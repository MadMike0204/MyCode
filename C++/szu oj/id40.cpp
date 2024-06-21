#include <iostream>
#include <string>
using namespace std;

struct exam
{
    long long num;
    string m1;
    string m2;
    string m3;
};

exam NewStu(int n)
{
    exam newnew;
    cin >> newnew.num >> newnew.m1 >> newnew.m2 >> newnew.m3;
    return newnew;
}

int Compare(exam &student1,exam &student2,int paper)
{
    int length,count = 0;
    if(paper == 1)
    {
        length = student1.m1.length();
        for(int i=0;i<length;i++)
        {
            if(student1.m1[i] == student2.m1[i])
            {
                count++;
            }
        }
        if(count*1.0/length > 0.8888888)
        {
            return 1;
        }
        else
        {
            return 0;   
        }
    }
    else if(paper == 2)
    {
        length = student1.m2.length();
        for(int i=0;i<length;i++)
        {
            if(student1.m2[i] == student2.m2[i])
            {
                count++;
            }
        }
        if(count*1.0/length > 0.8888888)
        {
            int jostar = count/length;
            return 2;
        }
        else
        {
            int jostar = count/length;
            return 0;   
        }
    }
    else
    {
        length = student1.m3.length();
        for(int i=0;i<length;i++)
        {
            if(student1.m3[i] == student2.m3[i])
            {
                count++;
            }
        }
        if(count*1.0/length > 0.8888888)
        {
            return 3;
        }
        else
        {
            return 0;   
        }
    }
}

int main(){

    int t;
    cin >> t;
    //初始化学生
    exam student[t];
    for(int i=0;i<t;i++)
    {
        student[i] = NewStu(1);
    }
    //比较抄袭
    for(int i=1;i<=3;i++)
    {
        for(int j=0;j<t-1;j++)
        {
            int temp = j;
            for(int k=j+1;k<t;k++)
            {
                if(Compare(student[j],student[k],i))
                {
                    cout << student[j].num << " " << student[k].num << " " << i << endl;
                }
            }
        }
    }
    return 0;
}