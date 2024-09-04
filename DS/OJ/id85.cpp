/*
题目描述

实现顺序表的存储结构和操作

属性包括：数组、实际长度、最大长度（设定为1000）

操作包括：创建、插入、删除、查找
输入

第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据
第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
第4行输入要删除的位置
第5行输入要删除的位置
第6行输入要查找的位置
第7行输入要查找的位置


输出

数据之间用空格隔开

第1行输出创建后的顺序表内容，包括顺序表实际长度和数据

每成功执行一次操作（插入或删除），输出执行后的顺序表内容

每成功执行一次查找，输出查找到的数据

如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出顺序表内容
*/
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class SqList
{
    private:
        static int default_max_length;
        int length;
        int max_length;
        T* list;
    public:
        SqList(int l,int m = SqList::default_max_length):length(l),max_length(m),list(nullptr){}
        ~SqList()
        {

        }
        void InitSqList()
        {
            list = new T[max_length = default_max_length];
            for(int i=0;i<length;i++)
            {
                cin >> list[i];
            }
            return;
        }
        int InsertSqList(int idx,T value)
        {
            if(idx > length+1 || idx <= 0)
            {
                cout << "error" << endl;
                return -1;
            }
            //如果插入位置有效，开始倒着移动1位
            for(int i=length-1;i>=idx-1;i--)
            {
                list[i+1] = list[i];
            }
            list[idx-1] = value;
            length++;
            return 1;
        }
        int RemoveSqList(int idx)
        {
            if(idx > length+1 || idx <= 0)
            {
                cout << "error" << endl;
                return -1;
            }
            list[idx-1] = -1;
            for(int i=idx-1;i<length-1;i++)
            {
                list[i] = list[i+1];
            }
            length--;
            return 1;
        }
        void PrintSqList()
        {
            cout << length << " ";
            for(int i=0;i<length;i++)
            {
                cout << list[i] << " ";
            }
            cout << endl;
        }
        T SearchSqList(int idx)
        {
            if(idx > length || idx <= 0)
            {
                cout << "error" << endl;
                return -1;
            }
            return list[idx-1];
        }
};
template<class T> int SqList<T>::default_max_length = 1000;

// void test()
// {

//     SqList<int> JO(5);
//     JO.InitSqList();
//     JO.PrintSqList();
//     JO.RemoveSqList(3);
//     JO.PrintSqList();
//     cout << JO.SearchSqList(3);

// }

int main(){

    int l,v,idx,ret;
    cin >> l;
    SqList<int> JO(l);
    JO.InitSqList();

    JO.PrintSqList();

    cin >> idx >> v;
    ret = JO.InsertSqList(idx,v);
    if(ret != -1)
        JO.PrintSqList();

    cin >> idx >> v;
    ret = JO.InsertSqList(idx,v);
    if(ret != -1)
        JO.PrintSqList();

    cin >> idx;
    ret = JO.RemoveSqList(idx);
    if(ret != -1)
        JO.PrintSqList();

    cin >> idx;
    ret = JO.RemoveSqList(idx);
    if(ret != -1)
        JO.PrintSqList();

    cin >> idx;
    int temp = JO.SearchSqList(idx);
    if(temp != -1)
        cout << temp << endl;

    cin >> idx;
    temp = JO.SearchSqList(idx);
    if(temp != -1)
        cout << temp << endl;

    return 0;
}