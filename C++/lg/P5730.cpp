#include<iostream>
#include<cstring>
using namespace std;

string num0[5] = {"XXX","X.X","X.X","X.X","XXX"};
string num1[5] = {"..X","..X","..X","..X","..X"};
string num2[5] = {"XXX","..X","XXX","X..","XXX"};
string num3[5] = {"XXX","..X","XXX","..X","XXX"};
string num4[5] = {"X.X","X.X","XXX","..X","..X"};
string num5[5] = {"XXX","X..","XXX","..X","XXX"};
string num6[5] = {"XXX","X..","XXX","X.X","XXX"};
string num7[5] = {"XXX","..X","..X","..X","..X"};
string num8[5] = {"XXX","X.X","XXX","X.X","XXX"};
string num9[5] = {"XXX","X.X","XXX","..X","XXX"};
string interval = ".";

class DisplayNum
{
    private:
        static string** data;
    public:
        static void Display(string,int);
        static void Initialize()
        {
            data[0] = num0;
            data[1] = num1;
            data[2] = num2;
            data[3] = num3;
            data[4] = num4;
            data[5] = num5;
            data[6] = num6;
            data[7] = num7;
            data[8] = num8;
            data[9] = num9;
        }
};

void DisplayNum::Display(string str,int n)
{
    string result[5];
    for(int i=0;i<n;i++)
    {
        int idx = str[i] - '0';
        for(int j=0;j<5;j++)
        {
            result[j] += data[idx][j];
        }
        if(i != n-1)
        {
            for(int j=0;j<5;j++)
            {
                result[j] += interval;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        cout << result[i] << endl;
    }
}
string** DisplayNum::data = new string*[10];
int main(){

    DisplayNum::Initialize();
    int N;
    cin >> N;
    string str;
    cin >> str;
    DisplayNum::Display(str,N);

    return 0;
}