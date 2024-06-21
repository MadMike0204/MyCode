#include <iostream>
#include <string>
using namespace std;

struct DateX
{
    int month;
    int year;
    int day;
    int id;
};

DateX NewPos(int n)
{
    DateX newnew;
    cin >> newnew.year >> newnew.month >> newnew.day;
    newnew.id = n;
    return newnew;
}
void Sortt()
{

}

int main(){

    int t;
    cin >> t;
        //输入
        DateX newnew[t];
        DateX temp;
        int rank[t];
        for(int i=0;i<t;i++)
        {
            newnew[i] = NewPos(i);
        }
        //排序
        int i,j,k;
        for(i=0;i<t-1;i++)
        {
            k = i;
            for(j=k+1;j<t;j++)    
            {
                if(newnew[k].year > newnew[j].year)
                {
                    temp = newnew[k];
                    newnew[k] = newnew[j];
                    newnew[j] = temp;
                }
                else if(newnew[k].year == newnew[j].year)
                {
                    if(newnew[k].month > newnew[j].month)
                    {
                        temp = newnew[k];
                        newnew[k] = newnew[j];
                        newnew[j] = temp;
                    }
                    else if(newnew[k].month == newnew[j].month)
                    {
                        if(newnew[k].day > newnew[j].day)
                        {
                            temp = newnew[k];
                            newnew[k] = newnew[j];
                            newnew[j] = temp;
                        }
                    }
                }
            }
        }
        
        //输出
        cout << newnew[1].year << "-" << newnew[1].month << "-" << newnew[1].day << endl;


    return 0;
}