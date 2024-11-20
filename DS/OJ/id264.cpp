#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MaxNodes = 210; // 定义最大节点数
int graph[MaxNodes][MaxNodes]; // 邻接矩阵表示图
int visited[MaxNodes]; // 记录节点访问情况
int nodeCount, edgeCount;

int main() {
    cin >> nodeCount >> edgeCount;

    // 初始化图的邻接矩阵
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < edgeCount; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = graph[y][x] = 1;
    }

    /*
    汉密尔顿回路的条件：
    1. 起点与终点相同
    2. 每相邻两个点间为通路
    3. 除起点外，其他所有点都出现过一次
    */
    int queryCount;
    cin >> queryCount;

    for (int q = 0; q < queryCount; q++) {
        int numNodesInPath;
        cin >> numNodesInPath;

        bool isHamiltonianCycle = true; // 标记是否为汉密尔顿回路
        memset(visited, 0, sizeof(visited)); // 重置访问记录

        vector<int> path(numNodesInPath);
        for (int j = 0; j < numNodesInPath; j++) {
            cin >> path[j];
        }

        int startNode = path[0], endNode = path[numNodesInPath - 1];

        // 条件1: 起点与终点必须相同
        if (startNode != endNode) {
            isHamiltonianCycle = false;
        }

        // 条件2: 相邻点之间必须有边相连
        for (int j = 1; j < numNodesInPath; j++) {
            if (graph[path[j - 1]][path[j]] != 1) {
                isHamiltonianCycle = false;
            }
            visited[path[j]]++;
        }

        // 条件3: 除起点外，其他所有节点必须出现且仅出现一次
        for (int i = 1; i <= nodeCount; i++) {
            if (visited[i] == 0 || (visited[i] == 2 && i != startNode)) {
                isHamiltonianCycle = false;
            }
        }
        cout << (isHamiltonianCycle ? "YES\n" : "NO\n");
    }

    return 0;
}
