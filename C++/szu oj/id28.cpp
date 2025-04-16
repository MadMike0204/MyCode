#include <iostream>
using namespace std;

// 定义表示人的结构体
struct Person {
    int number;         // 人的编号
    Person* next;       // 指向下一个人的指针
    
    // 构造函数
    Person(int num) : number(num), next(nullptr) {}
};

// 打印约瑟夫环的出圈顺序
void josephus(int n, int k, int m) {
    // 如果人数为0，直接返回
    if (n <= 0) return;
    
    // 创建循环链表
    Person* head = new Person(1);
    Person* current = head;
    
    // 创建剩余的n-1个节点
    for (int i = 2; i <= n; i++) {
        current->next = new Person(i);
        current = current->next;
    }
    
    // 将链表首尾相连，形成循环链表
    current->next = head;
    
    // 找到第k个人作为起始位置
    Person* prev = current;  // 指向当前节点的前一个节点
    current = head;
    for (int i = 1; i < k; i++) {
        prev = current;
        current = current->next;
    }
    
    // 开始报数和出圈
    while (n > 0) {
        // 报数到m
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }
        
        // 输出当前出圈的人的编号
        cout << current->number;
        if (n > 1) cout << " ";
        
        // 将当前节点从循环链表中删除
        prev->next = current->next;
        Person* temp = current;
        current = current->next;
        delete temp;
        
        n--; // 人数减1
    }
    cout << endl;
}

int main() {
    int n, k, m;
    
    // 读取多组测试数据
    while (cin >> n >> k >> m) {
        josephus(n, k, m);
    }
    
    return 0;
}
