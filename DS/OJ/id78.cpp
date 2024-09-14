#include <iostream>
using namespace std;
struct Mydata
{
    int exponent;
    int coefficient;
    Mydata(int exp,int c):exponent(exp),coefficient(c){}
};
class LinkList;// 预定义 方便设置友类
class LNode // 节点类 是链表的组成元素。
{
    friend class LinkList;
private:
    Mydata data;
    LNode* next;
public:
    LNode(Mydata e={0,0},LNode* pNext=nullptr):data(e),next(pNext){}
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
    int ListDelete(int i);
    int GetLength(); // 计算表长
    void TailInitial(int n);
    void ListDisplay();
    LinkList& MergeList(LinkList &another,bool flag);
};
LinkList& LinkList::MergeList(LinkList &another,bool flag=1) // 经过测试，只能正确合并递增序列
{   // 0~递减序列 1~递增序列
    LinkList *result = new LinkList;
    // 初始化指针，结果有序表指针初始化为头节点，this和another有序表初始化为第一个节点
    LNode *pa = head->next;  // this有序表
    LNode *pb = another.head->next; // another有序表
    LNode *pc = result->head; //结果有序表

    // 开始填充结果
    // flag = 1和flag = 0 分别对应两种赋值情况，if合并了其中赋值同一个节点的value的情况。
    while(pa && pb)
    {
        if((flag && pa->data.exponent < pb->data.exponent) 
        || (!flag && pa->data.exponent > pb->data.exponent)) 
        {
            pc->next = pa;
            pa = pa->next;
        }
        else if (pa->data.exponent == pb->data.exponent)
        {
            pc->next = pa;
            pa->data.coefficient += pb->data.coefficient;
            pa = pa->next;
            pb = pb->next;
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
void LinkList::TailInitial(int n)
{
    LNode* newNode,*tail = head;
    int exp,c;
    while(n--)
    {
        cin >> c >> exp;
        newNode = new LNode({exp,c});
        tail->next = newNode;
        tail = tail->next;
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
// void LinkList::ListDisplay()
// {
//     LNode* p = head->next;
//     while(p != nullptr)
//     {
//         cout << p->data.coefficient <<"x" << "^" << p->data.exponent << endl;
//         p = p->next;
//     }
// }
void LinkList::ListDisplay()
{
    int l = GetLength();
    int idx = 0;
    LNode* p = head->next;
    while(p != nullptr)
    {
        //系数部分
        if(p->data.coefficient == 0)
        {
            p = p->next;
            continue;
        }
        if(idx >= 1)
        {
            cout << " + ";
        }
        if(p->data.coefficient < 0)
        {
            cout << "(" << p->data.coefficient << ")";
        }
        else
        {
            cout << p->data.coefficient;
        }
        //指数部分
        if(p->data.exponent == 0)
        {
            // pass
        }
        else if(p->data.exponent < 0)
        {
            cout << "x" << "^(" << p->data.exponent << ")";
        }
        else
        {
            cout << "x" << "^" << p->data.exponent;
        }
        idx++;
        p = p->next;
    }
    cout << endl;
}
int LinkList::ListDelete(int i)
{
    if(i<=0)// 不能删除头结点
        return 0;

    LNode* p = GetElement(i-1);
    //这个判断可以除去越界的节点，因为当i越界时，GetElement会返回空指针；而且不必遍历链表获取有效长度。
    if(!p || !p->next)// 获得了空节点或者i-1节点的下一个节点是空的，说明节点无效
        return 0; // 表示删除失败
    
    LNode* temp = p->next->next; // 保存要删除的节点的next指针
    delete p->next;// 删除节点数据
    p->next = temp;// 更新i-1节点的next指针
    return 1;
}
int LinkList::GetLength()
{
    int l = 0;
    LNode* p = head->next;
    while(p)
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
    if(i < 0)
        return nullptr;

    LNode *result = head;
    int k = 0;
    while(result && k<i)   
    {
        result = result->next;
        k++;
    }
    return result?result:nullptr; // 杜绝返回野指针的可能性?
}
void testGenerate()
{
    LinkList jojo,spare,result;
    jojo.TailInitial(2);
    spare.TailInitial(2);
    result = jojo.MergeList(spare);
    result.ListDisplay();
}

int main(){

    int t,n;
    cin >> t;
    while(t--)
    {
        LinkList a,b,result;
        cin >> n;
        a.TailInitial(n);
        cin >> n;
        b.TailInitial(n);

        a.ListDisplay();
        b.ListDisplay();

        result = a.MergeList(b);
        result.ListDisplay();
    }

    return 0;
}