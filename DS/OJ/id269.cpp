#include <iostream>
using namespace std;

class Node; // 前置声明，方便设置友元关系

class Node {
    friend class List; // 设置List为友元类
private:
    int data;
    Node* next;
public:
    Node(int value = 0, Node* next_ptr = nullptr) : data(value), next(next_ptr) {}
    ~Node() = default;
};

class List {
private:
    Node* head;
    int size;
    int count;

public:
    List(); // 构造函数
    ~List(); // 析构函数
    void insert(int& data); // 插入节点
    bool find(int index, int& data); // 查找节点数据
    void show(); // 显示链表
};

List::List() {
    head = new Node(); // 初始化头节点
    size = 0;
    count = 0;
}

List::~List() {
    Node* current = head;
    Node* temp;
    while (current) {
        temp = current;
        current = current->next;
        delete temp;
    }
}

void List::insert(int& data) {
    Node* new_node = new Node(data); // 创建新节点
    Node* current = head;

    // 找到插入位置
    while (current->next && current->next->data < data) {
        current = current->next;
    }

    // 插入新节点
    new_node->next = current->next;
    if (current->next) {
        count++; // 记录非空指针变化
    }
    current->next = new_node;
    size++; // 更新链表大小
}

bool List::find(int index, int& data) {
    if (index <= 0 || index > size) {
        return false; // 索引超出范围
    }

    Node* current = head;
    // 查找到第index个节点
    while (index && current->next) {
        current = current->next;
        index--;
    }

    data = current->data;
    return true;
}

void List::show() {
    cout << "非空指针变化" << count << "次" << endl;
    Node* current = head;

    // 遍历链表并显示数据
    while (current->next->next) {
        current = current->next;
        cout << current->data << ' ';
    }
    cout << current->next->data << endl;
}

int main() {
    int t, temp, data;
    List list;

    // 插入操作
    cin >> t;
    while (t--) {
        cin >> temp;
        list.insert(temp);
    }
    list.show();

    // 查找操作
    cin >> t;
    while (t--) {
        cin >> temp;
        if (list.find(temp, data)) {
            cout << data << endl;
        } else {
            cout << "error" << endl;
        }
    }

    return 0;
}
