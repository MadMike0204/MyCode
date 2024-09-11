#include <iostream>
#include <cmath>
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
    ~LinkList();
    int Swap2Node(int a,int b);
    int ListInsert(int i,int e);
    int ListDelete(int i);
    int GetLength(); // 计算表长
    int FindElement(int idx);
    bool IsOperableIndex(int idx);
    void HeadInitial(int n);
    void TailInitial(int n);
    void ListDisplay();
    LinkList& MergeList(LinkList &another,bool flag);
};
bool LinkList::IsOperableIndex(int idx)
{
    if(idx >= 1 && idx <= GetLength())
        return 1;
    return 0;
}
int LinkList::Swap2Node(int a,int b)
{
    if(!(IsOperableIndex(a) && IsOperableIndex(b)))
        return 0;
    if(fabs(b-a) == 1)
    {
        LNode* pa = GetElement(a);
        LNode* pb = GetElement(b);
        LNode* tempBnext = GetElement(b)->next;
        LNode* pBefore_a = GetElement(a-1);

        pBefore_a->next = pb;
        pb->next = pa;
        pa->next = tempBnext;

        return 1;
    }
    LNode* tempAnext = GetElement(a)->next;
    LNode* tempBnext = GetElement(b)->next;
    LNode* pa = GetElement(a);
    LNode* pb = GetElement(b);
    LNode* pBefore_a = GetElement(a-1);
    LNode* pBefore_b = GetElement(b-1);

    // pBefore_a->next = pb;
    // pBefore_b->next = pa;
    // pb->next = tempAnext;
    // pa->next = tempBnext;
    pBefore_a->next = pb;
    pb->next = tempAnext;
    pBefore_b->next = pa;
    pa->next = tempBnext;


    
    return 1;
}
int LinkList::FindElement(int idx)
{
    LNode* temp = GetElement(idx);
    if(temp == NULL)
    {
        return 0;
    }
    return temp->data;
}
LinkList& LinkList::MergeList(LinkList &another,bool flag=1) // 经过测试，只能正确合并递增序列
{   // 0~递减序列 1~递增序列 还没实现
    LinkList *result = new LinkList;
    // 初始化指针，结果有序表指针初始化为头节点，this和another有序表初始化为第一个节点
    LNode *pa = head->next;  // this有序表
    LNode *pb = another.head->next; // another有序表
    LNode *pc = result->head; //结果有序表
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
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
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

    if(i < 0 || i > GetLength())//发现GetElement有出现bug，不能超过上限,已修改
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

int main(){

    int n,a,b;
    cin >> n;
    LinkList jo;
    jo.TailInitial(n);
    jo.ListDisplay();

    cin >> a >> b;
    if(jo.Swap2Node(a,b))
    {
        jo.ListDisplay();
    }
    else
    {
        cout << "error" << endl;
    }

    cin >> a >> b;
    if(jo.Swap2Node(a,b))
    {
        jo.ListDisplay();
    }
    else
    {
        cout << "error" << endl;
    }

    return 0;
}