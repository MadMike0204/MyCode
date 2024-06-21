/*
【id:378】【30分】A. 【期中测验】一、人民币（30分）
时间限制
1s
内存限制
128MB
题目描述

定义人民币类RMB，包含私有数据成员：元和角，都是非负整数。

公有成员函数包括:

1）自行设计方法，设置元、角值。

2）自行设计方法，访问元、角值。

3）其它函数根据需要自行设计。

定义一个全局函数compare，参数是两个人民币对象，功能是比较两个人民币对象的大小， 返回值为整数，参数1大于参数2则返回1，小于返回-1，等于返回0。

主函数中，实现两个人民币对象的数值设置，调用函数compare比较两个对象，并输出比较结果。

提示：1元=10角，输出结果要求把角转换为元，例如1元2角转换为1.2元 注意数据类型转换，例如55/100=0，55/100.0=0.55。

要求：

1) 用C++语言和面向对象设计思想编程实现题目要求。

2) 所有数据成员都是私有属性。

提示：在C++中，输出指定精度的参考代码如下：

#include <iostream>

#include <iomanip>

using namespace std;

int main( )

{

double a =3.141596;

cout << fixed << setprecision(3)<<a << endl;   //输出浮点数，保留三位小数

return 0;

}


输入

第1行输入t，表示有t个测试示例。

接着输入t行，每行输入四个参数(非负整数)，分别表示两个人民币对象的元和角， 角数值范围为0~~9，无需考虑非法数据输入。


输出

每个示例输出1行：两个人民币对象的比较结果。输出格式见示例，浮点数保留1位小数。
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
static double FF = 0.001;
class RMB
{
    private:
        int yuan;
        int jiao;
        double total;
    public:
        RMB()
        {
            yuan = 0;
            jiao = 0;
            total = 0;
        }
        void SetAll(int y,int j)
        {
            total = y + j * 0.1;
        }
        double getTotal()
        {
            return total;
        }
};

int main(){

    int t,a1,a2,b1,b2;
    cin >> t;
    RMB Newnew;
    RMB sword;
    while(t > 0)
    {   
        cin >> a1 >> b1 >> a2 >> b2;
        Newnew.SetAll(a1,b1);
        sword.SetAll(a2,b2);
        cout << fixed << setprecision(1) << Newnew.getTotal() << "yuan ";

        if(fabs(Newnew.getTotal()-sword.getTotal()) < FF)
        {
            cout << "= ";
        }
        else if(Newnew.getTotal() > sword.getTotal())
        {
            cout << "> ";
        }
        else 
        {
            cout << "< ";
        }
        cout << fixed << setprecision(1) << sword.getTotal() << "yuan" << endl;
        t--;
    }


    return 0;
}