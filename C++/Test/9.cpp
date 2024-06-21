#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
}*head,*p;
Node* createList();
void insertList(Node *head,int value);
void showList(Node* head,int i);

int main(){

    head = createList();
    showList(head,5);
    return 0;
}

Node* createList()
{
    Node* Head = new Node{0,NULL};
    int nodeNum,value;
    cin >> nodeNum;
    for(int i=1;i<=nodeNum;i++)
    {
        cin >> value;
        insertList(Head,value);
    }
    return Head;
}
void insertList(Node *Head,int value)
{
    Node* newnew = new Node;
    newnew->value = value;
    newnew->next = p->next;
    p->next = newnew;
}
void showList(Node* head,int i)
{
    Node* p = head->next;
    if(p)
    {
        while(p)
        {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
}
