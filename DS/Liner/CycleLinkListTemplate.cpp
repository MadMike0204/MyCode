#include <iostream>
using namespace std;
template<typename T>
class CycleLinkList;// 预定义 方便设置友类
template<typename T>
class LNode // 节点类 是链表的组成元素。
{
    friend class CycleLinkList<T>;
private:
    T data;
    LNode* next;
public:
    LNode(T e=0,LNode* pNext=NULL):next(pNext),data(e){}
    ~LNode(){};
};
template<typename T>
class CycleLinkList
{
private:
    LNode<T> *head; // 头指针
    LNode<T> *tail;
    LNode<T>* GetElement(int i);// 查找第i个节点并返回指针
public:
    CycleLinkList();
    ~CycleLinkList();
    int ListInsert(int i,T e);
    int ListDelete(int i);
    int GetLength(); // 计算表长
    void HeadInitial(int n);
    void TailInitial(int n);
    void ListDisplay();
    void SetTail();
    CycleLinkList<T>& MergeList(CycleLinkList<T> &another);
};
template<typename T>
void CycleLinkList<T>::SetTail()
{
    tail = GetElement(GetLength());
    tail->next = head;
}
template<typename T>
CycleLinkList<T>& CycleLinkList<T>::MergeList(CycleLinkList<T> &another) // 经过测试，只能正确合并递增序列
{   // 0~递减序列 1~递增序列 还没实现
    CycleLinkList<T> *result = new CycleLinkList<T>;
    // 初始化指针，结果有序表指针初始化为头节点，this和another有序表初始化为第一个节点
    LNode<T> *pa = head->next;  // this有序表
    LNode<T> *pb = another.head->next; // another有序表
    LNode<T> *pc = result->head; //结果有序表
    // 开始填充结果
    while(pa && pb) 
    {
        if(pa->data <= pb->data) // 如果b链的数据大于等于a链，则存放b链的数据
        {
            pc->next = pa;
            pa = pa->next;
        }
        else                     // 如果b链的数据小于 
        {
            pc->next = pb;
            pb = pb->next;
        }
        pc = pc->next;           // result链指针后移
    }
    // 上面while循环的结果是其中一个链表到头了,为null
    // 这段代码用来设置链表的尾节点
    pc->next = pa ? pa : (pb?pb:NULL); 
    // 逻辑说明:如果pa非NULL,则返回pa(pb肯定为null)
    // 反过来说,如果pa为NULL,那么要判断一下pb是不是NULL再返回.
    head->next = NULL; // this和another置空表
    another.head->next = NULL; 
    // 返回值为生成好的CycleLinkList引用
    return *result;
}
template<typename T>
void CycleLinkList<T>::TailInitial(int n)
{
    LNode<T>* newNode;
    tail = head;
    T e;
    while(n--)
    {
        cin >> e;
        newNode = new LNode(e,head);
        tail->next = newNode;
        tail = tail->next;
    }
}
template<typename T>
void CycleLinkList<T>::HeadInitial(int n)
{
    LNode<T>* newNode;
    T e;
    while(n--)
    {
        cin >> head->data;
        newNode = new LNode<T>(0,head);
        head = newNode;
    }
    SetTail();
}
template<typename T>
CycleLinkList<T>::~CycleLinkList()
{
    LNode<T>* p,*q;
    for(p = head;p&&p!=head;)
    {
        q = p;
        p = p->next;
        delete q;
    }
}
template<typename T>
void CycleLinkList<T>::ListDisplay()
{
    LNode<T>* p = head->next;
    while(p != head)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
template<typename T>
int CycleLinkList<T>::ListDelete(int i)
{
    LNode<T>* p = GetElement(i-1);
    if(p->next == head || !p)
        return 0; // 表示删除失败
    LNode<T>* temp = p->next->next;
    delete p->next;
    p->next = temp;
    return 1; 
}
template<typename T>
int CycleLinkList<T>::GetLength()
{
    int l = -1;
    LNode<T>* p;
    for(p = head;p!=head;)
    {
        l++;
        p = p->next;
    }

    return l;
}
template<typename T>
CycleLinkList<T>::CycleLinkList()
{
    head = new LNode<T>();
}
template<typename T>
LNode<T>* CycleLinkList<T>::GetElement(int i) //返回第i个节点的指针
{
    LNode<T> *result = head;
    int k = 0;

    if(i < 0)
        return NULL;
    while(i != k)   
    {
        if(result->next == head)
            return NULL;
        result = result->next;
        k++;
    }
    return result;
}
template<typename T>
int CycleLinkList<T>::ListInsert(int i,T e) // 第i个位置插入e
{
    LNode<T> *p = GetElement(i-1); // 获得指向i-1节点的数据
    if(p->next==head || p==head)                      // 这样，通过修改p的next指针为新节点 不应该在头节点中放入数据
        return 0;                    // 将新节点的next设置为第i个节点
                                     // 就算插入好节点
    
    LNode<T> *newNode = new LNode<T>(e,p->next);// 设置新节点的next指针和初始值
    p->next = newNode;// 设置第i-1节点的next指针
    SetTail();
    return 1;
}// 返回值为0,表示插入失败;返回值为1,表示插入成功.

void test1()
{
    CycleLinkList<double> jojo;
    double arr[10] = {1.9,2.8,3.77,4.234,5.23434,6.2345,7.83,8.2344,9.7122,10.5123};
    for(int i=1;i<=10;i++)
    {
        jojo.ListInsert(i,arr[i-1]);
    }
    cout << jojo.GetLength() << endl;
    jojo.ListDisplay();
}

void test2()
{
    CycleLinkList<int> jojo;
    jojo.TailInitial(5);
    jojo.ListDisplay();
}
void test3()//测试合并链表
{
    CycleLinkList<int> mergedList,a,b;
    a.TailInitial(5);
    b.TailInitial(5);
    mergedList = a.MergeList(b);
    cout << "合并后的链表长度为:" << mergedList.GetLength() << endl;
    cout << "原链表清零检测: a:" << a.GetLength() << " b:" << b.GetLength() << endl;
    cout << "以下为合并后的链表内容" << endl;
    mergedList.ListDisplay();
}

int main(){

    test2();

    return 0;
}