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
    LNode(int e=0,LNode* pNext=NULL):data(e),next(pNext){}
    ~LNode(){};
};
class LinkList
{
private:
    LNode *head; // 头指针
    LNode* GetElement(int i);// 查找第i个节点并返回指针
public:
    LinkList();
    int ListInsert(int i,int e);
    int ListDelete(int i);
    int GetLength(); // 计算表长
    void HeadInitial(int n);
    void TailInitial(int n);
    void ListDisplay();
    ~LinkList();
};
void LinkList::TailInitial(int n)
{
    LNode* newNode,*tail = head;
    int e;
    while(n--)
    {
        cin >> e;
        newNode = new LNode(e);
        tail->next = newNode;
        tail = tail->next;
    }
}
void LinkList::HeadInitial(int n)
{
    LNode* newNode;
    int e;
    while(n--)
    {
        cin >> head->data;
        newNode = new LNode(0,head);
        head = newNode;
    }
}
LinkList::~LinkList()
{
    LNode* p,*q;
    for(p = head;p;)
    {
        q = p;
        p = p->next;
        delete q;
    }
}
void LinkList::ListDisplay()
{
    LNode* p = head->next;
    while(p != nullptr)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
int LinkList::ListDelete(int i)
{
    LNode* p = GetElement(i-1);
    if(!p || !p->next)
        return 0; // 表示删除失败
    LNode* temp = p->next->next;
    delete p->next;
    p->next = temp;
    return 1;
}
int LinkList::GetLength()
{
    int l = -1;
    LNode* p;
    for(p = head;p;)
    {
        l++;
        p = p->next;
    }

    return l;
}
LinkList::LinkList()
{
    head = new LNode();
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
    if(!p || i == 0)                      // 这样，通过修改p的next指针为新节点 不应该在头节点中放入数据
        return 0;                    // 将新节点的next设置为第i个节点
                                     // 就算插入好节点
    
    LNode *newNode = new LNode(e,p->next);// 设置新节点的next指针和初始值
    p->next = newNode;// 设置第i-1节点的next指针
    return 1;
}// 返回值为0,表示插入失败;返回值为1,表示插入成功.

void test1()
{
    LinkList jojo;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i=1;i<=10;i++)
    {
        jojo.ListInsert(i,arr[i-1]);
    }
    cout << jojo.GetLength() << endl;
    jojo.ListDisplay();
}

void test2()
{
    LinkList jojo;
    jojo.TailInitial(5);
    jojo.ListDisplay();
}
int main(){

    test2();

    return 0;
}