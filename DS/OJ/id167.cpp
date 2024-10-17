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
        int KMPFindSubstrTimes(string p);
};
int myString::KMPFindSubstrTimes(string p)
{
    // 为KMP寻找子串作准备
    int L = p.length();
    int result = 0;
    int* next = new int[L];
    GetNext(p,next);
    // 开始进行循环
    int position = 0;
    int location;
    while(L + position <= this->size)
    {
        location = KMP(p,position,next);
        if(location != -1)
        {
            result++;
            position = location+1; // 从找到的子串，第一个字符之后开始下一轮查找
            continue;
        }
        break;// KMP没找到，说明后面不存在了
    }
    return result;
}
int myString::KMP(string p,int pos,int next[])
{
    int i,j;

    int length_data = data.length();
    int length_p = p.length();

    for(i=pos,j=0;i < length_data && j < length_p; )
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

int main(){

    int t;
    myString jo;
    string str;
    cin >> t;
    while(t--)
    {
        cin >> str;
        jo.InitialData(str);
        int N;
        cin >> N;

        string substrs[N];
        int result[N] = {0};
        for(int i=0;i<N;i++)
        {
            cin >> substrs[i];
            result[i] = jo.KMPFindSubstrTimes(substrs[i]);
        }
        for(int i=0;i<N;i++)
        {
            cout << substrs[i] << ":" << result[i] << endl;
        }

    }

    return 0;
}