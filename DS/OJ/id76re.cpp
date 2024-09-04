#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static string Statement[2] = {"close","open"};

struct Stock
{
    int year,month,day;
    bool state;
    int s1,s2;
    Stock()
    {
        year = month = day = state = s1 = s2 = 0;
    }
    void Set(int year,int month,int day,int s1,int s2,string s)
    {
        this->year = year;
        this->day = day;
        this->month = month;
        this->s1 = s1;
        this->s2 = s2;
        if(s == "open")
            state = 1;
        else
            state = 0;
    }
    Stock(const Stock& j)
    {
        this->year = j.year;
        this->day = j.day;
        this->month = j.month;
        this->s1 = j.s1;
        this->s2 = j.s2;
        this->state = j.state;
    }
};

bool CompareDates(const Stock& a,const Stock& b)
{
    if(a.year != b.year)
    {
        return a.year < b.year;
    }
    if(a.month != b.month)
    {
        return a.month < b.month;
    }
    return a.day < b.day;
}


int main(){

    vector<Stock> Jo;
    //input
    int num,length;
    int year,month,day,s1,s2;
    char temp;
    string state;
    cin >> num >> length;
    for(int i=0;i<num;i++)
    {
        cin >> year >> temp >> month >> temp >> day;
        cin >> state >> s1 >> s2;
        Stock temp;
        temp.Set(year,month,day,s1,s2,state);
        Jo.push_back(temp);
    }
    //divide 2
    vector<Stock> Open,Close;
    for(Stock element:Jo)
    {
        if(element.state)
        {
            Open.push_back(element);
        }
        else
        {
            Close.push_back(element);
        }
    }
    //sort
    std::sort(Open.begin(),Open.end(),CompareDates);
    std::sort(Close.begin(),Close.end(),CompareDates);
    //compute & print
    int num_close = Close.size();
    int num_open = Open.size();
    //open
    if(length <= Open.size())
    {
        int result_s1,result_s2;
        for(int i=length-1;i<Open.size();i++)
        {
            result_s1 = result_s2 = 0;
            for(int j = i;j>=i-length+1;j--)
            {
                result_s1 += Open[j].s1;
                result_s2 += Open[j].s2;
            }
            cout << Open[i].year << "/" << Open[i].month << "/" << Open[i].day
                 << " open " 
                 << result_s1/length << " " << result_s2/length << endl;
        }
    }
    //close
    if(length <= Close.size())
    {
        int result_s1,result_s2;
        for(int i=length-1;i<Close.size();i++)
        {
            result_s1 = result_s2 = 0;
            for(int j = i;j>=i-length+1;j--)
            {
                result_s1 += Close[j].s1;
                result_s2 += Close[j].s2;
            }
            cout << Close[i].year << "/" << Close[i].month << "/" << Close[i].day
                 << " close " 
                 << result_s1/length << " " << result_s2/length << endl;
        }
    }
    

    return 0;
}