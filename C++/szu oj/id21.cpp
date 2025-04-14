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
    LNode(int e=0,LNode* pNext=nullptr):data(e),next(pNext){}
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
    int ListInsert(int i,int e);
    int ListDelete(int i);
    int GetLength(); // 计算表长
    void HeadInitial(int n);
    void TailInitial(int n);
    void ListDisplay();
    LinkList& MergeList(LinkList &another,bool flag);
    int SearchElementByIndex(int idx);
};

int LinkList::SearchElementByIndex(int idx){
    LNode* temp = GetElement(idx);
    if(temp == nullptr || idx == 0){
        cout << "error" << endl;
        return -1;
    }
    cout << temp->data << endl;
    return 1;
}

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
{// 我的头节点是不存数据的，所以可以直接写入数据，再弄一个新的头结点
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

void solve(){

}

int main(){

    int t;
    cin >> t;
    LinkList jojo;
    jojo.TailInitial(t);
    cout << jojo.GetLength() << " ";
    jojo.ListDisplay();
    cout << endl;

    cin >> t;
    int idx;
    for(int i=0;i<t;i++){
        cin >> idx;
        jojo.SearchElementByIndex(idx);
    }


    return 0;
}