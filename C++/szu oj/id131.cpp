#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//填空实现类STU的定义
/********** Write your code here! **********/
class STU
{
    private:
        string name;
    public:
        STU(string name_in)
        {
            name = name_in;
            cout << "Construct student " << name << endl;
        }
        STU(const STU &p)
        {
            name = p.name + "_copy";
            cout << "Construct student " << name << endl;
        }
        ~STU()
        {
            cout << "Destruct student " << name << endl;
            name = "";
        }

};
/*******************************************/
//其他代码如下
int IDs; //全局变量，用于输出结果提示
class Tutor {
private:
	STU stu;
public:
	Tutor(STU & s): stu(s)
	{	
        cout<<"Construct tutor "<<IDs<<endl;	
    }
	~Tutor()
	{	
        cout<<"Destruct tutor "<<IDs<<endl;	
    }

};
void fuc(Tutor x)
{	cout<<"In function fuc()"<<endl;	}

int main()
{	cin>>IDs;
	STU s1("Tom"); //输入学生姓名Tom
	Tutor t1(s1);
	IDs++;
	cout<<"Calling fuc()"<<endl;
	fuc(t1);

	return 0;
}

/*【id:131】【30分】A. 【程序填空】Tutor类(拷贝构造+复合类)
时间限制
1s
内存限制
128MB
题目描述

已知主函数和Tutor类，请根据输入输出完成STU类定义


输入

输入一个参数，作为全局变量IDs的初始值，用于输出结果提示，看样例


输出

具体看样例*/