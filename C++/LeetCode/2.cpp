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

int ReadNode(ListNode &head,int length,int idx);
void PrintListNode(ListNode &head);
int GetLengthOfListNode(ListNode &head);

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* NewListNode; //newListNode to save the result to return 
        int* arr1 = NULL;
        int* arr2 = NULL;

        int MaxLengthOfResult = max(GetTheLengthOfListNode(l1),GetTheLengthOfListNode(l2)) + 1;
        arr1 = GetTheArrOfListNode(l1,arr1,MaxLengthOfResult);
        arr2 = GetTheArrOfListNode(l2,arr2,MaxLengthOfResult);
        
        cout << "The probable length of sum is:" << MaxLengthOfResult << endl;

        int* result = new int[MaxLengthOfResult];
        memset(result,0,sizeof(result));

        bool CFlag = 0;
        int TrueLength = 0;
        int final,a,b;
        for(int i=0;i<MaxLengthOfResult;i++)
        {
            result[i] = arr1[i] + arr2[i] + CFlag;
            a = arr1[i];
            b = arr2[i];
            final = result[i];
            if(result[i] >= 10)
            {
                result[i] %= 10;
                CFlag = 1;
            }
            else CFlag = 0;
        }
        
        TrueLength = MaxLengthOfResult;
        if(!result[MaxLengthOfResult-1] && TrueLength > 1)
           TrueLength--;

        ListNode* head = CreateAListNodeAccordingToAnArr(result,TrueLength);
        PrintListNode(*head);
        return head;
    }

    ListNode* CreateAListNodeAccordingToAnArr(int* arr,int length)//The ListNode to create and the Arr HAS THE SAME DIRECTION
    {   
        ListNode* Node;
        ListNode* Next = NULL;
        for(int i=0;i<length;i++)
        {
            Node = new ListNode(arr[i],Next);
            Next = Node;
        }
        return Node;
    }
    int* GetTheArrOfListNode(ListNode* head,int* arr,int length)
    {
        arr = new int[length];
        memset(arr,0,sizeof(arr));
        length = GetTheLengthOfListNode(head);
        int v;
        for(int i=0;i<length;i++)
        {
            arr[i] = ReadANode(head,length,i);
            v = arr[i];
            cout << v << endl;
        }
        return arr;
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
    int ReadANode(ListNode *head,int length,int idx)
    {
        length = GetTheLengthOfListNode(head);
        int value = -1;
        if(idx >= length)
        {
            return 0;
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
};

void test01()
{
    //create ListNode 1
    ListNode Lst1_Z(6);
    ListNode Lst1_Y(2,&Lst1_Z);
    ListNode Lst1_X(3,&Lst1_Y);

    //create ListNode 2
    ListNode Lst2_Z(3);
    ListNode Lst2_Y(1,&Lst2_Z);
    ListNode Lst2_X(5,&Lst2_Y);
    cout << GetLengthOfListNode(Lst2_X) << endl;
    PrintListNode(Lst2_X);
}

void test02()
{
    int arr[5] = {1,2,3,4,5};
    Solution jojo;
    ListNode* jo = jojo.CreateAListNodeAccordingToAnArr(arr,5);
    cout << ReadNode(*jo,5,1) << endl;
    PrintListNode(*jo);
}

void test03()
{
    Solution jojo;
    //create ListNode 1
    ListNode Lst1_Z(6);
    ListNode Lst1_Y(2,&Lst1_Z);
    ListNode Lst1_X(3,&Lst1_Y);

    //create ListNode 2
    ListNode Lst2_Z(3);
    ListNode Lst2_Y(1,&Lst2_Z);
    ListNode Lst2_X(7,&Lst2_Y);

    PrintListNode(*jojo.addTwoNumbers(&Lst1_X,&Lst2_X));

}

int main(){


    test03();

    return 0;
}

void PrintListNode(ListNode &head)
{
    int length = GetLengthOfListNode(head);
    int numN[length];
    for(int i=0;i<length;i++)
    {
        numN[i] = ReadNode(head,length,i);
    }
    for(int i=0;i<length;i++)
    {
        cout << numN[i] << ' ';
    }
    cout << endl;
}

int ReadNode(ListNode &head,int length,int idx)
{
    int value = -10086;
    int count = 0;
    ListNode* thisNode = &head;
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

int GetLengthOfListNode(ListNode &head)
{
    int count = 0;
    ListNode* thisNode = &head;
    while(thisNode != NULL)
    {
        count++;
        thisNode = thisNode->next;
    }
    return count;
}