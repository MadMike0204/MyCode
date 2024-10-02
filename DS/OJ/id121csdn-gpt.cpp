#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class GroupQueue {
private:
    vector<queue<int>> groupQueues; // 每组的队列
    queue<int> mainQueue;           // 主队列，存储队列的顺序
    vector<int> groupStatus;        // 标记组是否有元素在队列中
    vector<vector<int>> groupTable; // 分组表，记录元素所属的组
    int groupCount;                 // 组的总数

public:
    GroupQueue(int t) : groupCount(t) {
        groupQueues.resize(t);
        groupStatus.resize(t, 0);  // 初始化状态为0
        groupTable.resize(t, vector<int>(100, -1)); // 初始化表
    }

    void InputGroupTable() {
        for (int i = 0; i < groupCount; ++i) {
            int n;
            cin >> n;
            for (int j = 0; j < n; ++j) {
                int element;
                cin >> element;
                groupTable[i][j] = element; // 录入分组表
            }
        }
    }

    int FindGroupIndex(int value) {
        // 查找元素属于哪一组
        for (int i = 0; i < groupCount; ++i) {
            for (int j = 0; j < 100; ++j) {
                if (groupTable[i][j] == value) {
                    return i;
                }
            }
        }
        return -1; // 没找到则返回-1
    }

    void Enqueue(int value) {
        int groupIndex = FindGroupIndex(value);
        if (groupIndex == -1) return; // 如果找不到对应组则直接返回

        groupQueues[groupIndex].push(value);

        // 如果该组没有元素在主队列中，加入主队列并更新状态
        if (groupStatus[groupIndex] == 0) {
            mainQueue.push(groupIndex);
            groupStatus[groupIndex] = 1;
        }
    }

    void Dequeue(bool &firstOutput) {
        if (!mainQueue.empty()) {
            int groupIndex = mainQueue.front();

            if (!groupQueues[groupIndex].empty()) {
                if (!firstOutput) {
                    cout << " "; // 添加空格
                }
                cout << groupQueues[groupIndex].front();
                groupQueues[groupIndex].pop();
                firstOutput = false; // 确保后续输出有空格分隔
            }

            // 如果组队列为空，从主队列移除并更新状态
            if (groupQueues[groupIndex].empty()) {
                mainQueue.pop();
                groupStatus[groupIndex] = 0;
            }
        }
    }

    void ProcessCommands() {
        string command;
        bool firstOutput = true; // 控制是否输出空格

        while (cin >> command) {
            if (command == "STOP") {
                break;
            } else if (command == "ENQUEUE") {
                int value;
                cin >> value;
                Enqueue(value);
            } else if (command == "DEQUEUE") {
                Dequeue(firstOutput);
            }
        }
        cout << endl; // 保证最后输出有换行符
    }
};

int main() {
    int t;
    cin >> t;

    GroupQueue groupQueue(t);
    groupQueue.InputGroupTable();   // 输入分组表
    groupQueue.ProcessCommands();   // 处理指令

    return 0;
}
