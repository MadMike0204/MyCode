#include<iostream>
#include<string>
using namespace std;

class myString
{
    private:
        string data;
        int size;
        void GetNext(string p,int next[]);
        int KMP(string p,int pos,int next[]);
    public:
        myString();
        ~myString();
        void InitialData(string p);
        int KMPFindSubstr(string p,int pos);
        void Replace(string p,string str);
        void Print();
};

void myString::Print()
{
    cout << data << endl;
}

void myString::Replace(string p, string str)
{
    int L = p.length();
    int* next = new int[L];

    GetNext(p,next);

    int position = KMP(p,0,next);

    if(position == -1)
        return;
    
    string part1,part2;

    for(int i=0;i<position;i++)
    {
        part1 += this->data[i];
    }
    for(int i=position+L;i<size;i++)
    {
        part2 += this->data[i];
    }

    string result = part1 + str + part2;
    InitialData(result);
}

int myString::KMP(string p,int pos,int next[])
{
    int i,j;

    int length_data = data.length();
    int length_p = p.length();

    for(i=0,j=0;i < length_data && j < length_p; )
    {
        if(j == -1 || data[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j == p.length())
    {
        return i-j;
    }
    return -1;
}
void myString::GetNext(string p,int next[])
{
    int i,j;
    i = 0;
    j = -1;
    // next数组 第一个默认为-1 下标从0开始
    next[i] = j;
    while(i < p.length() - 1)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

myString::myString()
{
    size = 0;
    data = "";
}
myString::~myString()
{
    size = 0;
    data = "";
}
void myString::InitialData(string p)
{
    data = "";
    data.assign(p);
    size = data.length();
}
int myString::KMPFindSubstr(string p,int pos)
{
    // 声明并分配next数组
    int L = p.length();
    int* next = new int[L];
    // 获得next值
    GetNext(p,next);
    // 输出next值
    for(int i = 0;i<L;i++)
        cout << next[i] << ' ';
    cout << endl;
    // v定义为返回值，如果v还是-1，说明没找到
    // 否则将会获得需要的位置
    int v = -1;
    v = KMP(p,pos,next);

    delete[] next;

    return v;
}

void test()
{
    myString jojo;
    string str = "doingdoing";
    string sub = "ing";
    jojo.InitialData(str);
    int location = jojo.KMPFindSubstr(sub,0);
    cout << location+1 << endl;
}

void test2()
{
    myString jojo;
    string str = "doingdoing";
    string sub = "in";
    string substitude = "WAAAAAAA";
    jojo.InitialData(str);
    jojo.Replace(sub,substitude);
    jojo.Print();
}

int main(){

    int t;
    cin >> t;
    myString jojo;
    string origin,substr,substitude;
    while(t--)
    {
        cin >> origin >> substr >> substitude;
        jojo.InitialData(origin);
        jojo.Print();
        jojo.Replace(substr,substitude);
        jojo.Print();
    }

    return 0;
}