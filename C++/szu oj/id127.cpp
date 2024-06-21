#include <iostream>
using namespace std;

static char user_type[4][20] = {"机构","企业","个人","备份"}; // A B C D
static char tel_state[3][20] = {"在用","未用","停用"}; // 1 2 3

class Date
{
    private:
        int year;
        short month;
        short day;
    public:
        Date(int year_in,short month_in,short day_in)
        {
            year = year_in;
            month = month_in;
            day = day_in;
        }
        int getyear()
        {
            return year;
        }
        short getmonth()
        {
            return month;
        }
        short getday()
        {
            return day;
        }
};

class Phone
{
    private:
        char type;
        string number;
        short state;
        Date* p_date;
    public:
        Phone(char type_in,string number_in,short state_in,int year,short month,short day)
        {
            type = type_in;
            number = number_in;
            state = state_in;
            p_date = NULL;
            cout << "Construct a new phone " << number << endl
                 << "类型=" << user_type[type-65] 
                 << "||号码=" << number 
                 << "||State=" << tel_state[state-1] << endl;
        }
        Phone(const Phone &pp)
        {
            type = 'D';
            number = pp.number;
            state = pp.state;
            cout << "Construct a copy of phone " << number << endl
                 << "类型=" << user_type[type-65] 
                 << "||号码=" << number  << "X"
                 << "||State=" << tel_state[state-1];
            if(state == 3)
            {
                p_date = new Date(pp.p_date->getyear(),
                                  pp.p_date->getmonth(),
                                  pp.p_date->getday());
                cout << "||停机日期="
                     << p_date->getyear() << "."
                     << p_date->getmonth() << "."
                     << p_date->getday() << endl;
            }
            else
            {
                cout << endl;
            }
        }
        void EndTel(int year,short month,short day)
        {
            state = 3;
            p_date = new Date(year,month,day);
            cout << "Stop the phone " << number << endl
                 << "类型=" << user_type[type-65] 
                 << "||号码=" << number 
                 << "||State=" << tel_state[state-1] 
                 << "||停机日期=" 
                 << p_date->getyear() << "."
                 << p_date->getmonth() << "."
                 << p_date->getday() << endl;
        }
};


int main(){

    int t;
    cin >> t;
    short state,month,day;
    string number;
    int year;
    char type;
    while(t > 0)
    {
        cin >> type >> number >> state >> year >> month >> day;
        Phone newnew(type,number,state,year,month,day);
        Phone newnew_copy(newnew);
        newnew.EndTel(year,month,day);
        cout << "----" << endl;
        t--;
    }

    return 0;
}

/*【id:127】【30分】B. 手机服务（构造+拷贝构造+堆）
时间限制
1s
内存限制
128MB
题目描述

设计一个类来实现手机的功能。它包含私有属性：号码类型、号码、号码状态、停机日期；包含方法：构造、拷贝构造、打印、停机。

1、号码类型表示用户类别，只用单个字母，A表示机构，B表示企业、C表示个人

2、号码是11位整数，用一个字符串表示

3、号码状态用一个数字表示，1、2、3分别表示在用、未用、停用

4、停机日期是一个日期对象指针，在初始化时该成员指向空，该日期类包含私有属性年月日，以及构造函数和打印函数等

----------------------------------------

5、构造函数的作用就是接受外来参数，并设置各个属性值,并输出提示信息，看示例输出

6、拷贝构造的作用是复制已有对象的信息，并输出提示信息，看示例输出。

想一下停机日期该如何复制，没有停机如何复制？？已经停机又如何复制？？

7、打印功能是把对象的所有属性都输出，输出格式看示例

8、停机功能是停用当前号码，参数是停机日期，无返回值，操作是把状态改成停用，并停机日期指针创建为动态对象，并根据参数来设置停机日期，最后输出提示信息，看示例输出

-------------------------------------------

要求：在主函数中实现号码备份的功能，对已有的虚拟手机号的所有信息进行复制，并将号码类型改成D表示备份；将手机号码末尾加字母X


输入

第一行输入t表示有t个号码

第二行输入6个参数，包括号码类型、号码、状态、停机的年、月、日，用空格隔开

依次输入t行


输出

每个示例输出三行，依次输出原号码信息、备份号码信息和原号码停机后的信息

每个示例之间用短划线（四个）分割开，看示例输出


样例查看模式 
正常显示
查看格式*/