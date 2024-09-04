#include <iostream>
using namespace std;

static string Statement[2] = {"close","open"};

struct CDate 
{
        int year, month, day;
        CDate(int y=0,int m=0,int d=0)
        {
            year = y;
            month = m;
            day = d;
        }
        void Set(int y,int m,int d)
        {
            year = y;
            month = m;
            day = d;
        }
        void print()
        {
            cout << year << "/" << month << "/" << day << endl;
        }
};

struct StockData
{

    int S1,S2,idx;
    CDate date;
    bool state,isvalid;//如果是开盘就是1，如果是收盘就是0 isvalid 是否有平均值,决定是否输出
    int S1_ba,S2_ba;
    void Evaluate(int y,int m,int d,int s1,int s2,string s,int id)
    {
        idx = id;
        date.day = d;
        date.month = m;
        date.year = y;
        S1 = s1;
        S2 = s2;
        if(s == "open")
            state = 1;
        else
            state = 0;
    }
    StockData operator=(StockData &aim)
    {
        this->date.day = aim.date.day;
        this->date.month = aim.date.month;
        this->date.year = aim.date.year;
        return *this;
    }
    static int Compare(StockData &a,StockData &b)
    {
        if(a.date.year > b.date.year)
            return 1;
        else if(a.date.year < b.date.year)
            return -1;
        else if(a.date.month > b.date.month)
            return 1;
        else if(a.date.month < b.date.month)
            return -1;
        else if(a.date.day > b.date.day)
            return 1;
        else if(a.date.month < b.date.month)
            return -1;
        return 0;
    }
    static void SortStockData(StockData* S,int N)
    {
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(Compare(S[i],S[j]) == 1)
                {
                    StockData temp = S[i];
                    S[i] = S[j];
                    S[j] = temp;
                }
            }
        }
    }
    void Print()
    {
        cout << date.year << "/" << date.month << "/" << date.day << " " 
             << Statement[state] << " " << S1_ba << " " << S2_ba << endl;
    }
};

int main(){

    int N,M;
    cin >> N >> M;
    StockData JO[N];

    int y,m,d,S1,S2;
    char temp;
    string state;
    for(int i=0;i<N;i++)
    {
        cin >> y >> temp >> m >> temp >> d;
        cin >> state >> S1 >> S2;
        JO[i].Evaluate(y,m,d,S1,S2,state,i);
    }
    int close,open;
    close = open = 0;
    for(int i=0;i<N;i++)
    {
        if(JO[i].state == 0)
        {
            close++;
        }
        else
        {
            open++;
        }
    }
    StockData OPEN[open];
    StockData CLOSE[close];
    int c1,c2;
    c1 = c2 = 0;
    for(int i=0;i<N;i++)
    {   
        if(JO[i].state == 0)
        {
            CLOSE[c1] = JO[i];
            c1++;
        }
        else
        {
            OPEN[c2] = JO[i];
            c2++;
        }
    }
    StockData::SortStockData(CLOSE,close);
    StockData::SortStockData(OPEN,open);
    int sum1,sum2;
    if(close >= M)
    {
        for(int i=0;i<M-1;i++)
        {
            CLOSE[i].isvalid = 0;
        }
        for(int i=M-1;i<close;i++)
        {
            CLOSE[i].isvalid = 1;
            sum1 = CLOSE[i].S1;
            sum2 = CLOSE[i].S2;
            for(int j=i-1;j>i-M;j--)
            {
                sum1 += CLOSE[j].S1;
                sum2 += CLOSE[j].S2;
            }
            CLOSE[i].S1_ba = sum1/M;
            CLOSE[i].S2_ba = sum2/M;
        }
        for(int i=0;i<close;i++)
        {
            if(CLOSE[i].isvalid)
            {
                CLOSE[i].Print();
            }
        }
    }
    

    return 0;
}