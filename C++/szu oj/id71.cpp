#include <iostream>
#include <vector> // 用于方便地读取输入数据

// 单链表节点结构
struct SNode {
    int data;
    SNode *next;
    // 构造函数（可选，方便节点创建）
    SNode(int val) : data(val), next(nullptr) {}
};

// 单链表类
class CList {
public:
    SNode *head; // 表头指针

    // 1. 构造函数：初始化 head
    CList() {
        head = nullptr;
    }

    // 6. 析构函数：释放链表每个节点的堆内存
    ~CList() {
        SNode *current = head;
        SNode *nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next; // 保存下一个节点
            delete current;          // 删除当前节点
            current = nextNode;      // 移动到下一个节点
        }
        head = nullptr; // 确保头指针置空
    }

    // 2. createList(int *value, int n): 用 value 中的 n 个数据创建单链表
    void createList(int *value, int n) {
        // 如果链表已存在，先清空（虽然在本题测试方式下不是必须，但通常是个好习惯）
        // 如果不清空，则此函数会覆盖现有链表
        SNode *current = head;
        SNode *nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;


        if (n <= 0) {
            return; // 如果没有数据，则链表为空
        }

        // 创建头节点
        head = new SNode(value[0]);
        // head->next = nullptr; // SNode 构造函数已处理

        SNode *tail = head; // 指向当前链表的最后一个节点

        // 依次创建并链接后续节点
        for (int i = 1; i < n; ++i) {
            SNode *newNode = new SNode(value[i]);
            // newNode->next = nullptr; // SNode 构造函数已处理
            tail->next = newNode; // 将新节点链接到链表末尾
            tail = newNode;       // 更新尾指针
        }
    }

    // 3. printList(): 以 head 为表头依次输出每个节点的数据值
    void printList() {
        if (head == nullptr) {
            // 根据示例输出，空链表也需要换行
            std::cout << std::endl;
            return;
        }
        SNode *current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " "; // 节点间用空格分隔
            }
            current = current->next;
        }
        std::cout << std::endl; // 输出结束后换行
    }

    // 4. insertNode(int pos, int value): 在单链表第 pos 个节点位置后插入新节点
    //    pos 是 1-based 索引，表示在第 pos 个节点之后插入
    void insertNode(int pos, int value) {
        // pos <= 0 是无效位置
        // 如果 pos = 0, 按题意应理解为在第0个节点后，这不合理，视为错误
        if (pos <= 0) {
            std::cout << "error" << std::endl;
            return;
        }

        SNode *current = head;
        int count = 1;

        // 寻找第 pos 个节点
        while (current != nullptr && count < pos) {
            current = current->next;
            count++;
        }

        // 如果 current 为 nullptr，说明 pos 超出了链表范围
        if (current == nullptr) {
            std::cout << "error" << std::endl;
            return;
        }

        // 找到了第 pos 个节点 (current)，在其后插入新节点
        SNode *newNode = new SNode(value);
        newNode->next = current->next; // 新节点的 next 指向原 pos 节点的下一个节点
        current->next = newNode;       // 原 pos 节点的 next 指向新节点

        // 插入成功后打印链表
        printList();
    }

    // 5. removeNode(int pos): 删除第 pos 个节点 (1-based 索引)
    void removeNode(int pos) {
        // pos <= 0 是无效位置，或者链表为空
        if (pos <= 0 || head == nullptr) {
            std::cout << "error" << std::endl;
            return;
        }

        SNode *nodeToRemove = nullptr;
        SNode *prev = nullptr; // 指向要删除节点的前一个节点

        // 情况 1: 删除头节点 (pos = 1)
        if (pos == 1) {
            nodeToRemove = head;
            head = head->next; // 更新头指针
        } else {
            // 情况 2: 删除非头节点
            prev = head;
            int count = 1;
            // 寻找第 pos-1 个节点
            while (prev != nullptr && count < pos - 1) {
                prev = prev->next;
                count++;
            }

            // 检查第 pos-1 个节点 (prev) 和第 pos 个节点 (prev->next) 是否存在
            if (prev == nullptr || prev->next == nullptr) {
                // 如果 prev 是空 (pos > 链表长度 + 1)
                // 或者 prev->next 是空 (pos 正好是链表长度 + 1，即要删除的节点不存在)
                std::cout << "error" << std::endl;
                return;
            }

            // 找到了要删除节点的前一个节点 (prev)
            nodeToRemove = prev->next;      // 指向要删除的节点
            prev->next = nodeToRemove->next; // 将前一个节点链接到被删除节点的下一个节点
        }

        // 释放被删除节点的内存
        delete nodeToRemove;

        // 删除成功后打印链表
        printList();
    }
};

// 主函数，用于处理输入和测试
int main() {
    int testCases;
    std::cin >> testCases; // 读取测试次数
    while (testCases--) {
        CList list; // 为每个测试用例创建一个新的链表对象

        int n;
        std::cin >> n; // 读取初始数据个数
        // 使用 std::vector 来动态存储初始数据
        std::vector<int> initialData(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> initialData[i]; // 读取初始数据
        }
        // 使用数组指针创建链表
        list.createList(initialData.data(), n);
        // 打印创建后的链表
        list.printList();

        int m;
        std::cin >> m; // 读取插入次数
        for (int i = 0; i < m; ++i) {
            int pos, value;
            std::cin >> pos >> value; // 读取插入位置和数据
            list.insertNode(pos, value); // 执行插入操作（内部会打印结果或错误）
        }

        int k;
        std::cin >> k; // 读取删除次数
        for (int i = 0; i < k; ++i) {
            int pos;
            std::cin >> pos; // 读取删除位置
            list.removeNode(pos); // 执行删除操作（内部会打印结果或错误）
        }
        // list 对象在此处超出作用域，会自动调用析构函数释放内存
    }
    return 0;
}
