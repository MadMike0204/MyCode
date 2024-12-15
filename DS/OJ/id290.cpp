#include <iostream>
using namespace std;

#define TABLE_SIZE 11 // 哈希表大小

// 哈希函数
int getHash(int key) {
    return key % TABLE_SIZE;
}

struct Node {
    int key;       // 存储的值
    Node* next;    // 指向下一个节点

    Node(int k, Node* p = nullptr) : key(k), next(p) {} // 构造函数
};

class HashTable {
private:
    Node* table[TABLE_SIZE]; // 哈希表数组，存储链表的头节点

public:
    // 构造函数，初始化哈希表
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // 尾插法
    void insert(Node* newNode, int index) {
        if (!table[index]) {
            table[index] = newNode;
            return;
        }

        Node* current = table[index];
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // 查找值并返回比较次数，如果未找到返回 0
    int search(int key) {
        int index = getHash(key);
        int comparisons = 0;
        Node* current = table[index];

        while (current) {
            comparisons++;
            if (current->key == key) {
                return comparisons; // 找到，返回比较次数
            }
            current = current->next;
        }
        return 0; // 未找到
    }
};

int main() {
    int n, t, key;
    cin >> n;

    HashTable hashTable; // 创建哈希表

    // 插入数据到哈希表
    while (n--) {
        cin >> key;
        int index = getHash(key);
        Node* newNode = new Node(key);
        hashTable.insert(newNode, index);
    }

    cin >> t;

    // 查询数据并处理结果
    while (t--) {
        cin >> key;
        int comparisons = hashTable.search(key);
        if (comparisons == 0) {
            cout << "error" << endl;
            Node* newNode = new Node(key);
            hashTable.insert(newNode, getHash(key));
        } else {
            cout << getHash(key) << " " << comparisons << endl;
        }
    }

    return 0;
}
