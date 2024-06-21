#include <iostream>
using namespace std;

class CGame
{
    private:
        static int wincounter;
        int length;
        int wrong_time;
        int correct_time;
        char** Rect;
    public:
        CGame()
        {
            wrong_time = 0;
            correct_time = 0;
            Rect = NULL;
        }
        void initial(int N)
        {
            length = N;
            Rect = new char*[length];
            for(int i=0;i<length;i++)
            {
                Rect[i] = new char;
            }
        }
        void reset()
        {
            for(int i=0;i<length;i++)
            {
                delete Rect[i];
            }
            delete Rect;
        }
        int getCounter()
        {
            return wincounter;
        }
        void counter()
        {
            wincounter++;
        }
        int checkToContinue()
        {
            if(wrong_time == 3)
            {
                return 0;
            }
            else if(correct_time == (length*length)/2)
            {
                return -1;
            }
            return 1;
        }
        void Match(int x1,int y1,int x2,int y2)
        {
            x1--;y1--;x2--;y2--;
            if(Rect[x1][y1] == Rect[x2][y2])
            {
                correct_time ++;
            }
            else
            {
                wrong_time ++;
            }
        }

        void GetC()
        {
            for(int i=0;i<length;i++)
            {
                for(int j=0;j<length;j++)
                {
                    cin >> Rect[i][j];
                }
            }
        }
        void PrintC()
        {
            for(int i=0;i<length;i++)
            {
                for(int j=0;j<length;j++)
                {
                    cout << Rect[i][j];
                }
                cout << endl;
            }
            cout << endl;
        }
};
int CGame::wincounter = 0;
void test()
{
    CGame jojo;
    jojo.GetC();
    jojo.PrintC();
}
int main(){

    int t,N;
    cin >> t;
    CGame sword;
    while(t > 0)
    {
        cin >> N;
        sword.initial(N);
        sword.GetC();
        int times;
        cin >> times;
        int a,b,c,d,flag = 1;
        for(int i=0;i<times;i++)
        {
            cin >> a >> b >> c >> d;
            sword.Match(a,b,c,d);
            if(flag != 0 && flag != -1)
                flag = sword.checkToContinue();
        }
        if(flag == -1)
        {
            cout << "Congratulations" << endl;
            sword.counter();
        }
        else
        {
            cout << "Game Over" << endl;
        }
        sword.reset();
        t--;
    }
    cout << sword.getCounter() << endl;
    return 0;
}














/*
【id:380】【20分】C. 【期中测验】三、简易连连看（20分）
时间限制
1s
内存限制
128MB
题目描述

本题要求实现一个简易连连看游戏模拟程序：给定一个N×N（2≤N≤20且N为偶数）的方阵网格游戏盘面，每个格子中放置一个符号。这些符号一定是成对出现的，同一个符号可能不止一对。程序读入玩家给出的一对位置(x1,y1)、(x2,y2)（1≤x1,x2,y1,y2≤20），判断这两个位置上的符号是否匹配。如果匹配成功（位置不同且相同符号，不为“*”），则将两个符号消为“*”。若匹配错误达到3次，则输出“Game Over”并结束游戏。或者当全部符号匹配成功，即每个格子里都是“*”时，则输出“Congratulations”，然后结束游戏。 请用类CGame模拟该游戏，游戏会运行多次。请在类中设置一个私有的静态变量counter，记录游戏一共赢了多少次。

注：初始游戏盘面无“*”。


输入

第一行输入测试次数

每次测试输入格式如下：第1行是盘面大小N；第2行到第N+1行是每行的N个符号；第N+2行是位置对的次数M；第N+3行到第N+M+2行是一对位置(x1,y1)、(x2,y2)的值。


输出

每次测试数据输出一行游戏结果（Game Over或Congratulations）。 最后一行输出游戏共赢了多少次。



*/