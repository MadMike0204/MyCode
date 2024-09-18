#include <iostream>
using namespace std;
class Stack
{
private:
    int* data;
    int top;
    static int MaxSize;
public: 
    Stack()
    {
        data = new int[MaxSize];
        top = 0;
    }
    ~Stack()
    {
        if(data)
            delete[] data;
    }
    bool IsFull();
    bool IsEmpty();
    int Push(int e);
    int Pop();
    void Print();
    int GetTopE();
    int GetAndPop();
};
int Stack::GetAndPop()
{
    if(IsEmpty())
    {
        cout << "Get top Element error" << endl;
        exit(-1);
    }
    return data[--top];
}
int Stack::GetTopE()
{
    if(IsEmpty())
    {
        cout << "Get top Element error" << endl;
        exit(-1);
    }
    return data[top-1];
}
void Stack::Print()
{
    if(IsEmpty())
        return;
    int l = top;
    for(int i=l-1;i>=0;i--)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
int Stack::Push(int e)
{
    if(!IsFull())
    {
        data[top++] = e;
        return 1;
    }
    return 0;
}
int Stack::Pop()
{
    if(!IsEmpty())
    {
        top--;
        return 1;
    }
    return 0;
}
bool Stack::IsFull()
{
    if(top == MaxSize)
        return 1;
    return 0;
}
bool Stack::IsEmpty()
{
    if(top == 0)
        return 1;
    return 0;
}

int Stack::MaxSize = 100;
int main()
{
    Stack jo;
    for(int i=0;i<1;i++)
    {
        jo.Push(i);
    }
    for(int i=0;i<50;i++)
    {
        jo.Pop();
    }
    jo.Print();
    return 0;
}