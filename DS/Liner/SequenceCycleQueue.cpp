#include <iostream>
using namespace std;

template<typename T>
class SequenceCycleQueue
{
private:
    static int MaxSize;
    T* data;
    int front,rear;
    int currentLength;
public:
    SequenceCycleQueue();
    int Push(T e);
    bool IsEmpty();
    bool IsFull();
    T GetFront();
    int Pop();
};
template<typename T>
int SequenceCycleQueue<T>::MaxSize = 1000; 

template<typename T>
SequenceCycleQueue<T>::SequenceCycleQueue()
{
    data = new T[MaxSize];
    front = 1;
    rear = 0;
    currentLength = 0;
}
// 使用计数器判别空和满
template<typename T>
bool SequenceCycleQueue<T>::IsEmpty() // 为空返回1
{
    if(currentLength)
        return 0;
    return 1;
}
template<typename T>
bool SequenceCycleQueue<T>::IsFull() // 已满返回1
{
    if(currentLength == MaxSize)
        return 1;
    return 0;
}
template<typename T>
T SequenceCycleQueue<T>::GetFront()
{
    if(IsEmpty())
    {
        cout << "Error occured" << endl;
        exit(-1);
    }
    return data[front];
}
template<typename T>
int SequenceCycleQueue<T>::Pop()
{
    if(IsEmpty())
        return 0;
    front = (front+1)%MaxSize;
    currentLength--;
    return 1;
}
template<typename T>
int SequenceCycleQueue<T>::Push(T e)
{
    if(IsFull())
        return 0;
    rear = (rear+1)%MaxSize;
    currentLength++;
    data[rear] = e;
    return 1;
}

void test()
{
    SequenceCycleQueue<double> jo;
    for(int i=1;i<=500;i++)
    {
        jo.Push(i*0.1);
    }
    for(int i=1;i<=600;i++)
    {
        cout << jo.GetFront() << " ";
        jo.Pop();
    }
    cout << endl;
}

int main(){

    test();

    return 0;
}


