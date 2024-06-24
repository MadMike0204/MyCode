#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(T data):
        data(data),next(nullptr){}
};

template <typename T>
class LinkedList
{
    private:
        Node<T>* head;
    public:
        LinkedList():
            head(nullptr){}
        ~LinkedList()
        {
            clear();
        }

        void push_front(T data)
        {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = head;
            head = newNode;
        }
        void pop_front()
        {
            if(head != nullptr)
            {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }
        void print() const
        {
            Node<T>* current = head;
            while(current != nullptr)
            {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << "nullptr" << std::endl;
        }
        void clear()
        {
            while(head != nullptr)
            {
                pop_front();
            }
        }
};

int main(){

    LinkedList<int> list;

    list.push_front(10);
    list.push_front(999);
    list.push_front(2333);

    list.print();

    list.pop_front();

    list.print();

    return 0;
}