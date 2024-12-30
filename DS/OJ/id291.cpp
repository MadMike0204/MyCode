#include <iostream>
using namespace std;

#define EMPTY -123 // 空值标记

int getHash(int key) {
    return key % 11; // 哈希函数
}

// 节点类
struct Node {
    int num;      // 节点存储的值
    Node* next;   // 指向下一个节点的指针

    Node() : num(EMPTY), next(nullptr) {} // 默认构造函数
    Node(int n) : num(n), next(nullptr) {} // 带参数的构造函数
};

// 哈希表类
class HashTable {
private:
    Node* table;    // 哈希表的头节点数组
    int elementCount; // 初始数据元素个数

public:
    HashTable(int count) : elementCount(count) {
        table = new Node[11]; // 创建哈希表（链表数组）
        initializeTable();
        populateTable();
    }

    ~HashTable() {
        delete[] table; // 释放内存
    }

    // 初始化哈希表
    void initializeTable() {
        for (int i = 0; i < 11; i++) {
            table[i].next = nullptr;
        }
    }

    // 填充哈希表
    void populateTable() {
        while (elementCount--) {
            int key;
            cin >> key;
            insertElement(key);
        }
    }

    // 插入元素到哈希表
    void insertElement(int key) {
        int hashIndex = getHash(key);
        Node* newNode = new Node(key);
        newNode->next = table[hashIndex].next;
        table[hashIndex].next = newNode;
    }

    // 搜索元素并输出结果
    void searchElement(int target) {
        int hashIndex = getHash(target);
        int searchCount = 0;
        Node* current = table[hashIndex].next;

        // 遍历链表进行查找
        while (current != nullptr) {
            searchCount++;
            if (current->num == target) {
                cout << hashIndex << " " << searchCount << endl;
                return;
            }
            current = current->next;
        }

        // 未找到，插入新节点并输出错误信息
        insertElement(target);
        cout << "error" << endl;
    }
};

int main() {
    int n;
    cin >> n;

    HashTable hashTable(n); // 创建哈希表

    int queries;
    cin >> queries; // 查询次数
    while (queries--) {
        int target;
        cin >> target;
        hashTable.searchElement(target); // 查找目标值
    }

    return 0;
}
