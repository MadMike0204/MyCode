#include <iostream>
using namespace std;

struct item
{
    int exponent;
    int coefficent;
};

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
    LNode(T e=0,LNode* pNext=NULL):next(pNext),data(e){}
};

template<>
LNode<item>::LNode(item A,LNode<item>* pNext)
{
    data.coefficent = A.coefficent;
    data.exponent = A.exponent;
    pNext = NULL;
}


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
    void ListDisplay();
    LinkList<T>& MergeList(LinkList<T> &another);
};
template<typename T>
LinkList<T>& LinkList<T>::MergeList(LinkList<T> &another) // 经过测试，只能正确合并递增序列
{   // 0~递减序列 1~递增序列 还没实现
    LinkList<T> *result = new LinkList<T>;
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
    // 返回值为生成好的LinkList引用
    return *result;
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
    LNode<T>* p = GetElement(i-1);
    if(!p || !p->next)
        return 0; // 表示删除失败
    LNode<T>* temp = p->next->next;
    delete p->next;
    p->next = temp;
    return 1;
}
template<typename T>
int LinkList<T>::GetLength()
{
    int l = -1;
    LNode<T>* p;
    for(p = head;p;)
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
    LNode<T> *result = head;
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

int main(){

    LinkList<item> jo;

    return 0;
}