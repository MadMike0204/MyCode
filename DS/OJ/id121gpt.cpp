#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class GroupQueue {
private:
    vector<queue<int>> groupQueues; // n个队列共同构成组队列
    vector<int> groupSizes;         // 记录每组中的元素个数
    vector<vector<int>> elements;   // 记录每组的各个元素
    vector<int> status;             // 状态数组，标识该组是否有元素在队列中
    int headIndex, tailIndex;       // 组队列中存在元素队列的下标最小值和最大值
    int dequeueCount;               // 记录有多少个DEQUEUE操作
    int groupCount;                 // 组的总数

public:
    GroupQueue(int n) : groupCount(n), headIndex(0), tailIndex(0), dequeueCount(0) {
        groupQueues.resize(n);
        groupSizes.resize(n);
        status.resize(n, 0);         // 初始组队列为空，状态数组全置为0
        elements.resize(n);          // 初始化二维数组
    }

    void InputElements() {
        for (int i = 0; i < groupCount; ++i) {
            cin >> groupSizes[i];
            elements[i].resize(groupSizes[i]);
            for (int j = 0; j < groupSizes[i]; ++j) {
                cin >> elements[i][j];
            }
        }
    }

    void Enqueue(int value) {
        int groupIndex = FindGroupIndex(value);

        if (status[groupIndex] == 0) { // 如果该组还没有元素进入队列
            groupQueues[tailIndex].push(value);
            tailIndex++;
            status[groupIndex] = 1;
        } else {  // 如果该组已经有元素在队列中
            for (int i = headIndex; i < tailIndex; ++i) {
                if (IsInSameGroup(groupQueues[i].front(), groupIndex)) {
                    groupQueues[i].push(value);
                    break;
                }
            }
        }
    }

    void Dequeue() {
        dequeueCount++;
    }

    void ProcessDequeue() {
        for (int i = 0; i < dequeueCount; ++i) {
            int value = groupQueues[headIndex].front();
            groupQueues[headIndex].pop();

            cout << value;
            if (i != dequeueCount - 1)
                cout << ' ';
            else
                cout << endl;

            if (groupQueues[headIndex].empty())
                headIndex++;
        }
    }

    void ProcessCommands() {
        string command;
        while (cin >> command) {
            if (command == "STOP")
                break;
            else if (command == "ENQUEUE") {
                int value;
                cin >> value;
                Enqueue(value);
            } else if (command == "DEQUEUE") {
                Dequeue();
            }
        }
    }

private:
    int FindGroupIndex(int value) {
        for (int i = 0; i < groupCount; ++i) {
            for (int j = 0; j < groupSizes[i]; ++j) {
                if (value == elements[i][j])
                    return i;
            }
        }
        return -1; // 未找到对应组，实际场景应该不会发生
    }

    bool IsInSameGroup(int queueFrontValue, int groupIndex) {
        for (int i = 0; i < groupSizes[groupIndex]; ++i) {
            if (queueFrontValue == elements[groupIndex][i])
                return true;
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n; // n代表组数

    GroupQueue groupQueue(n);
    groupQueue.InputElements();
    groupQueue.ProcessCommands();
    groupQueue.ProcessDequeue();

    return 0;
}
