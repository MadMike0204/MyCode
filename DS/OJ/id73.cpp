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
    T GetData()
    {
        return data;
    }
    LNode<T>* GetNextP()
    {
        return next;
    }
};
template<typename T>
class CycleLinkList
{
private:
    LNode<T>* head; // 头指针
    LNode<T>* tail;
    
public:
    CycleLinkList();
    ~CycleLinkList();
    int ListInsert(int i,T e);
    int ListDelete(int i);
    void ListDeleteByP(LNode<T>* currentP);
    int GetLength(); // 计算表长
    void ListDisplay();
    void SetTail();
    LNode<T>* GetElement(int i);// 查找第i个节点并返回指针
};
template<typename T>
void CycleLinkList<T>::ListDeleteByP(LNode<T>* currentP)
{
    LNode<T>* temp = currentP->next;
    LNode<T>* pBeforeCurrentP;
    while(temp != currentP)
    {
        pBeforeCurrentP = temp;
        temp = temp->next;
    }
    pBeforeCurrentP->next = currentP->next;
    delete temp;
}
template<typename T>
void CycleLinkList<T>::SetTail()
{
    tail = GetElement(GetLength());
    tail->next = head;
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
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
template<typename T>
int CycleLinkList<T>::ListDelete(int i)
{
    LNode<T>* p = GetElement(i-1);
    if(p == head || !p)
        return 0; // 表示删除失败
    LNode<T>* temp = p->next->next;
    delete p->next;
    p->next = temp;
    return 1; 
}
template<typename T>
int CycleLinkList<T>::GetLength()
{
    int l = 0;
    LNode<T>* p;
    for(p = head;p->next!=head && p->next;)
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
    LNode<T>* p = GetElement(i-1);
    
    LNode<T> *newNode = new LNode<T>(e,p->next);// 设置新节点的next指针和初始值
    p->next = newNode;// 设置第i-1节点的next指针
    SetTail();
    return 1;
}// 返回值为0,表示插入失败;返回值为1,表示插入成功.

int main(){

    int t,N,outnum,begin;
    int count;
    cin >> t;
    while(t--)
    {
        // 初始化约瑟夫环
        cin >> N >> outnum >> begin;
        CycleLinkList<int> ring;
        for(int i=1;i<=N;i++)
        {
            ring.ListInsert(i,i);
        }

        // 开始报数,报数到outnum就删除该节点并输出该节点的值
        count = 1;
        LNode<int>*temp = ring.GetElement(begin);
        LNode<int>*tempNext = temp->GetNextP();
        bool flag = 0; // 是否重置开始报数
        while(1)
        {
            if(ring.GetLength() == 1)
                break;
            if(temp->GetData() == 0) // 跳过头节点
            {
                temp = temp->GetNextP();
                continue;
            }
            count %= outnum;
            if(count == 0) // 输出和删除 出列者
            {
                cout << temp->GetData() << " ";
                tempNext = temp->GetNextP();
                ring.ListDeleteByP(temp);
                flag = 1;
            }
            if(flag) // 删除节点后的重置
            {
                temp = tempNext;
                flag = 0;
                count = 1;
            }
            else // 下一个人报数
            {
                temp = temp->GetNextP();
                count++;
            }
            
        }
        cout << ring.GetElement(1)->GetData() << " " << endl;
    }
    return 0;
}