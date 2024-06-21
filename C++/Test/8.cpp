#include <iostream>
using namespace std;
/* 
head:头节点地址
*p
*/
struct Node
{
    int man;
    Node* next;
}*Head,*p;

void insertList(Node* head,int i,int man);

Node* creatList()
{
    Node* head = new Node{0,NULL};
    int n,man;
    cin >> n;
    for(int j=1;j<=n;j++)
    {
        cin >> man;
        insertList(head,j,man);
    }
    return head;
}

int main(){

    Node* head;
    Node* x = new Node;

    return 0;
}

void insertList(Node* head,int i,int man)
{
    Node* s = new Node;
    s -> man = man;
    s -> next = p->next;
    p -> next = s;
}