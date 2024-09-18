#include <iostream>
using namespace std;
struct Position
{
    int x,y;
    ostream& operator <<(const Position &p)
    {

    }
};
template<typename T>
class Stack
{
private:
    T* data;
    int top;
    static int MaxSize;
public: 
    Stack()
    {
        data = new T[MaxSize];
        top = 0;
    }
    ~Stack()
    {
        if(data)
            delete[] data;
    }
    bool IsFull();
    bool IsEmpty();
    int Push(T e);
    int Pop();
    void Print();
    int GetTopE();
    int GetAndPop();
};
template<typename T>
int Stack<T>::GetAndPop()
{
    if(IsEmpty())
    {
        cout << "Get top Element error" << endl;
        exit(-1);
    }
    return data[--top];
}
template<typename T>
int Stack<T>::GetTopE()
{
    if(IsEmpty())
    {
        cout << "Get top Element error" << endl;
        exit(-1);
    }
    return data[top-1];
}
template<typename T>
void Stack<T>::Print()
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
template<typename T>
int Stack<T>::Push(T e)
{
    if(!IsFull())
    {
        data[top++] = e;
        return 1;
    }
    return 0;
}
template<typename T>
int Stack<T>::Pop()
{
    if(!IsEmpty())
    {
        top--;
        return 1;
    }
    return 0;
}
template<typename T>
bool Stack<T>::IsFull()
{
    if(top == MaxSize)
        return 1;
    return 0;
}
template<typename T>
bool Stack<T>::IsEmpty()
{
    if(top == 0)
        return 1;
    return 0;
}
template<typename T>
int Stack<T>::MaxSize = 100;
int main()
{
    Stack<double> jo;
    for(int i=0;i<60;i++)
    {
        jo.Push(i*0.1);
    }
    for(int i=0;i<50;i++)
    {
        jo.Pop();
    }
    jo.Print();
    return 0;
}