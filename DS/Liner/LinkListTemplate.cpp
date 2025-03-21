#include <iostream>
using namespace std;
template<typename T>
class LinkList;// 预定义 方便设置友类
template<typename T>
class LNode // 节点类 是链表的组成元素。
{
    friend class LinkList<T>;
private:
    T data;
    LNode* next;
public:
    LNode(T e=0,LNode* pNext=NULL):data(e),next(pNext){}
    ~LNode(){};
};
template<typename T>
class LinkList
{
private:
    LNode<T> *head; // 头指针
    LNode<T>* GetElement(int i);// 查找第i个节点并返回指针
public:
    LinkList();
    ~LinkList();
    int ListInsert(int i,T e);
    int ListDelete(int i);
    int GetLength(); // 计算表长
    void HeadInitial(int n);
    void TailInitial(int n);
    void ListDisplay();
    LinkList<T>& MergeList(LinkList<T> &another,bool flag=1);
};
template<typename T>
LinkList<T>& LinkList<T>::MergeList(LinkList<T> &another,bool flag) // 经过测试，只能正确合并递增序列
{   // 0~递减序列 1~递增序列
    LinkList<T> *result = new LinkList<T>;
    // 初始化指针，结果有序表指针初始化为头节点，this和another有序表初始化为第一个节点
    LNode<T> *pa = head->next;  // this有序表
    LNode<T> *pb = another.head->next; // another有序表
    LNode<T> *pc = result->head; //结果有序表

    // 开始填充结果
    // flag = 1和flag = 0 分别对应两种赋值情况，if合并了其中赋值同一个节点的value的情况。
    while(pa && pb)
    {
        if((flag && pa->data <= pb->data) || (!flag && pa->data >= pb->data)) 
        {
            pc->next = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pb = pb->next;
        }
        pc = pc->next;           // result链指针后移
    }
    // 上面while循环的结果是其中一个链表到头了,为nullptr
    // 这段代码用来设置链表的尾节点
    pc->next = pa ? pa : (pb?pb:nullptr); 
    // 逻辑说明:如果pa非nullptr,则返回pa(pb肯定为nullptr)
    // 反过来说,如果pa为nullptr,那么要判断一下pb是不是nullptr再返回.
    head->next = nullptr; // this和another置空表
    another.head->next = nullptr; 
    // 返回值为生成好的LinkList引用
    return *result;
}
template<typename T>
void LinkList<T>::TailInitial(int n)
{
    LNode<T>* newNode,*tail = head;
    T e;
    while(n--)
    {
        cin >> e;
        newNode = new LNode<T>(e);
        tail->next = newNode;
        tail = tail->next;
    }
}
template<typename T>
void LinkList<T>::HeadInitial(int n)
{
    LNode<T>* newNode;
    T e;
    while(n--)
    {
        cin >> head->data;
        newNode = new LNode<T>(0,head);
        head = newNode;
    }
}
template<typename T>
LinkList<T>::~LinkList()
{
    LNode<T>* p,*q;
    for(p = head;p;)
    {
        q = p;
        p = p->next;
        delete q;
    }
}
template<typename T>
void LinkList<T>::ListDisplay()
{
    LNode<T>* p = head->next;
    while(p != nullptr)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
template<typename T>
int LinkList<T>::ListDelete(int i)
{
    if(i<=0)// 不能删除头结点
        return 0;

    LNode<T>* p = GetElement(i-1);
    //这个判断可以除去越界的节点，因为当i越界时，GetElement会返回空指针；而且不必遍历链表获取有效长度。
    if(!p || !p->next)// 获得了空节点或者i-1节点的下一个节点是空的，说明节点无效
        return 0; // 表示删除失败
    
    LNode<T>* temp = p->next->next; // 保存要删除的节点的next指针
    delete p->next;// 删除节点数据
    p->next = temp;// 更新i-1节点的next指针
    return 1;
}
template<typename T>
int LinkList<T>::GetLength()
{
    int l = 0;
    LNode<T>* p = head->next;
    while(p)
    {
        l++;
        p = p->next;
    }
    return l;
}
template<typename T>
LinkList<T>::LinkList()
{
    head = new LNode<T>();
}
template<typename T>
LNode<T>* LinkList<T>::GetElement(int i) //返回第i个节点的指针
{
    if(i < 0)
        return nullptr;

    LNode<T> *result = head;
    int k = 0;
    while(result && k<i)   
    {
        result = result->next;
        k++;
    }
    return result?result:nullptr; // 杜绝返回野指针的可能性?
}
template<typename T>
int LinkList<T>::ListInsert(int i,T e) // 第i个位置插入e
{
    LNode<T> *p = GetElement(i-1); // 获得指向i-1节点的数据
    if(!p || i == 0)                      // 这样，通过修改p的next指针为新节点 不应该在头节点中放入数据
        return 0;                    // 将新节点的next设置为第i个节点
                                     // 就算插入好节点
    
    LNode<T> *newNode = new LNode<T>(e,p->next);// 设置新节点的next指针和初始值
    p->next = newNode;// 设置第i-1节点的next指针
    return 1;
}// 返回值为0,表示插入失败;返回值为1,表示插入成功.

void test1()
{
    LinkList<double> jojo;
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
    LinkList<double> jojo;
    jojo.TailInitial(5);
    jojo.ListDisplay();
}
void test3()//测试合并链表
{
    LinkList<double> mergedList,a,b;
    a.TailInitial(3);
    b.TailInitial(3);
    mergedList = a.MergeList(b);
    cout << "合并后的链表长度为:" << mergedList.GetLength() << endl;
    cout << "原链表清零检测: a:" << a.GetLength() << " b:" << b.GetLength() << endl;
    cout << "以下为合并后的链表内容" << endl;
    mergedList.ListDisplay();
}

int main(){

    test3();

    return 0;
}