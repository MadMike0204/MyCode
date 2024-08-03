#include <iostream>
#include <cstring>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* NewListNode; //newListNode to save the result to return 
        
        int val;
        bool CO;
        int length = max(GetTheLengthOfListNode(l1),GetTheLengthOfListNode(l2));
        for(int i=0;i<length;i++)
        {
            val = ReadANode(l1,i) + ReadANode(l2,i) + CO;
            if(val >= 10)
            {
                CO = 1;
                val %= 10;
            }
            else
                CO = 0;
            NewListNode = AddANodeAtTheEnd(NewListNode,val);
        }
        if(CO)
            NewListNode = AddANodeAtTheEnd(NewListNode,1);

        return NewListNode;
    }

    int GetTheLengthOfListNode(ListNode* head)
    {
        int count = 0;
        ListNode* thisNode = head;
        while(thisNode != NULL)
        {
            count++;
            thisNode = thisNode->next;
        }
        return count;
    }
    int ReadANode(ListNode *head,int idx)
    {
        int length = GetTheLengthOfListNode(head);
        int value = 0;
        if(idx >= length)
        {
            return value;
        }
        int count = 0;
        ListNode* thisNode = head;
        while(count < length)
        {
            if(count == idx)
            {
                value = thisNode->val;
                break;
            }
            count++;
            thisNode = thisNode->next;
        }
        return value;
    }
    ListNode* AddANodeAtTheEnd(ListNode* head,int val)
    {
        //空链表特判
        if(head == NULL)
        {
            head = new ListNode(val,NULL); 
            return head;
        }
        //初始化头节点
        ListNode* thisNode = head;
        //为本节点创建指向下一节点的指针
        while(thisNode->next != NULL)
        {
            thisNode = thisNode->next;
        }
        thisNode->next = new ListNode(val,NULL);

        return head;
    }
};

void test1()
{
    //create ListNode 1
    ListNode Lst1_Z(6);
    ListNode Lst1_Y(2,&Lst1_Z);
    ListNode Lst1_X(3,&Lst1_Y);

    //create ListNode 2
    ListNode Lst2_Z(3);
    ListNode Lst2_Y(1,&Lst2_Z);
    ListNode Lst2_X(5,&Lst2_Y);

    Solution jojo;
    cout << "The origin length of the listnode is: " << jojo.GetTheLengthOfListNode(&Lst1_X) << endl;

    jojo.AddANodeAtTheEnd(&Lst1_X,999);

    cout << "That of the edited one is: " << jojo.GetTheLengthOfListNode(&Lst1_X) << endl;
}

void test2()
{
    //create ListNode 1
    ListNode Lst1_Z(6);
    ListNode Lst1_Y(2,&Lst1_Z);
    ListNode Lst1_X(3,&Lst1_Y);

    //create ListNode 2
    ListNode Lst2_Z(3);
    ListNode Lst2_Y(1,&Lst2_Z);
    ListNode Lst2_X(5,&Lst2_Y);

    Solution jojo;
    
    ListNode* N = jojo.addTwoNumbers(&Lst1_X,&Lst2_X);
    int length = jojo.GetTheLengthOfListNode(N);
    for(int i=0;i<length;i++)
    {
        cout << jojo.ReadANode(N,i);
    }
}

void test3()
{
    
}

int main(){

    test2();

    return 0;
}