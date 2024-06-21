#include <iostream>
#include <cmath>
using namespace std;

class Group
{
    public:
        virtual int add(int x, int y)=0;//输出加法的运算结果
        virtual int sub(int x, int y)=0;//输出减法的运算结果
};
class GroupA:public Group
{
    public:
        virtual int add(int x,int y)
        {
            return x+y;
        }
        virtual int sub(int x,int y)
        {
            return x-y;
        }
};
class GroupB:public Group
{
    public:
        virtual int add(int x,int y)
        {
            return x+y;
        }
        virtual int sub(int x,int y)
        {
            int result = 0;
            int xx[7] = {0},yy[7] = {0};
            for(int i=0;i<7;i++)
            {
                xx[i] = x % 10;
                yy[i] = y % 10;
                x /= 10;
                y /= 10;
                xx[i] -= yy[i];
                if(xx[i] < 0)
                {
                    xx[i] += 10;
                }
                result += xx[i] * (int)pow(10,i);
            }
            return result;
        }
};
class GroupC:public Group
{
    public:
        virtual int add(int x,int y)
        {
            int result = 0;
            int xx[7] = {0},yy[7] = {0};
            for(int i=0;i<7;i++)
            {
                xx[i] = x % 10;
                yy[i] = y % 10;
                x /= 10;
                y /= 10;
                xx[i] += yy[i];
                if(xx[i] >= 10)
                {
                    xx[i] -= 10;
                }
                result += xx[i] * (int)pow(10,i);
            }
            return result;
        }
        virtual int sub(int x,int y)
        {
            int result = 0;
            int xx[7] = {0},yy[7] = {0};
            for(int i=0;i<7;i++)
            {
                xx[i] = x % 10;
                yy[i] = y % 10;
                x /= 10;
                y /= 10;
                xx[i] -= yy[i];
                if(xx[i] < 0)
                {
                    xx[i] += 10;
                }
                result += xx[i] * (int)pow(10,i);
            }
            return result;
        }
};
     
int main(){

    int t,type,x,y;
    char op;
    Group* jojo = NULL;
    cin >> t;
    while(t > 0)
    {
        cin >> type;
        scanf("%d%c%d",&x,&op,&y);
        if(type == 1)
        {
            jojo = new GroupA;
        }
        else if(type == 2)
        {
            jojo = new GroupB;
        }
        else if(type == 3)
        {
            jojo = new GroupC;
        }
        if(op == '+')
        {
            cout << jojo->add(x,y) << endl;
        }
        else if(op == '-')
        {
            cout << jojo->sub(x,y) << endl;
        }
        t--;
    }

    return 0;
}