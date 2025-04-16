#include <iostream>
#include <string>
using namespace std;

// 定义链表节点结构体
struct Node {
    string data;
    Node* next;
    Node(string val) : data(val), next(nullptr) {}
};

// 尾插法创建链表
Node* createList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        
        Node* newNode = new Node(str);
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

// 冒泡排序实现（降序）
void bubbleSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;
    
    do {
        swapped = false;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            // 如果当前节点小于下一个节点，则交换
            if (ptr1->data < ptr1->next->data) {
                // 交换数据
                string temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// 打印链表
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

// 释放链表内存
void freeList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        Node* head = createList(n);
        bubbleSort(head);
        printList(head);
        
        // 释放内存
        freeList(head);
        
        // 添加空行分隔（除了最后一个测试用例）
        if (i < t - 1) {
            cout << endl;
        }
    }
    
    return 0;
}
