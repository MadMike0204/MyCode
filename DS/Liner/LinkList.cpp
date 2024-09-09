#include <iostream>
using namespace std;
class LinkList;// 预定义 方便设置友类
class LNode // 节点类 是链表的组成元素。
{
    friend class LinkList;
private:
    int data;
    LNode* next;
public:
    LNode(int e=0,LNode *pNext=NULL):data(e),next(pNext){}
    ~LNode(){};
};
class LinkList
{
private:
    LNode *head; // 头指针
    int GetLength(); // 计算表长
    LNode* GetElement(int i);// 查找第i个节点并返回指针
public:
    LinkList();
    int ListInsert(int i,int e);//
    int ListDelete(int i,int &e);
    void ListDisplay();
    ~LinkList();
};
int LinkList::GetLength()
{
    int l;

    return l;
}
LNode* LinkList::GetElement(int i) //返回第i个节点的指针
{
    LNode *result = head;
    int k = 0;

    if(i < 0)
        return NULL;
    while(i != k)
    {
        result = result->next;
        k++;
    }
    return result;
}
int LinkList::ListInsert(int i,int e) // 第i个位置插入e
{
    LNode *p = GetElement(i-1); // 获得指向i-1节点的数据
    if(!p)                      // 这样，通过修改p的next指针为新节点
        return 0;                    // 将新节点的next设置为第i个节点
                                     // 就算插入好节点
    LNode *newNode = new LNode(e,p->next);
    return 1;
}// 返回值为0,表示插入失败;返回值为1,表示插入成功.

int main(){



    return 0;
}