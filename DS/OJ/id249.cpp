#include <iostream>
#include <vector>
#include <string>
#include <climits> // For INT_MAX

using namespace std;

const int MaxLength = 100;

struct Vertex {
    int index;
    string data;
} vertex[MaxLength];

struct Path {
    int head;
    int tail;
};

class Map {
private:
    int adjacencyMatrix[MaxLength][MaxLength] = {0}; // 邻接矩阵
    int vertexNumber; // 顶点数
    int totalCost = 0; // 最小生成树总权值
    vector<Path> mstEdges; // 最小生成树边
    int parent[MaxLength]; // 并查集父节点数组
    int edgeCount = 0; // 最小生成树中的边数

    // 查找顶点索引
    int getVertexIndex(const string& vertexName) {
        for (int i = 0; i < vertexNumber; ++i) {
            if (vertex[i].data == vertexName) {
                return i;
            }
        }
        return -1;
    }

    // 并查集：查找根节点
    int findRoot(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findRoot(parent[x]);
    }

    // 并查集：合并集合
    void unionSets(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
    void kruskalAlgorithm() {
        for (int k = 0; k < vertexNumber - 1; ++k) {
            int minCost = INT_MAX;
            int u = -1, v = -1;

            // 寻找权值最小的边
            for (int i = 0; i < vertexNumber; ++i) {
                for (int j = i + 1; j < vertexNumber; ++j) {
                    if (adjacencyMatrix[i][j] > 0 && adjacencyMatrix[i][j] < minCost &&
                        findRoot(i) != findRoot(j)) {
                        minCost = adjacencyMatrix[i][j];
                        u = i;
                        v = j;
                    }
                }
            }

            // 如果找到有效边，加入最小生成树
            if (u != -1 && v != -1) {
                unionSets(u, v);
                mstEdges.push_back({u, v});
                totalCost += minCost;
                ++edgeCount;
            }
        }

        // 检查是否形成了一个连通图
        if (edgeCount == vertexNumber - 1) {
            cout << totalCost << endl;
            for (const auto& edge : mstEdges) {
                cout << vertex[edge.head].data << ' ' << vertex[edge.tail].data << ' '
                     << adjacencyMatrix[edge.head][edge.tail] << endl;
            }
        } else {
            cout << "-1" << endl; // 无法形成连通图
        }
    }

public:
    Map() {
        cin >> vertexNumber;

        // 初始化并查集
        for (int i = 0; i < vertexNumber; ++i) {
            parent[i] = i;
        }

        // 输入顶点信息
        for (int i = 0; i < vertexNumber; ++i) {
            cin >> vertex[i].data;
            vertex[i].index = i;
        }

        // 输入边信息
        int edgeNumber;
        cin >> edgeNumber;
        for (int i = 0; i < edgeNumber; ++i) {
            string tail, head;
            int weight;
            cin >> tail >> head >> weight;

            int indexTail = getVertexIndex(tail);
            int indexHead = getVertexIndex(head);

            adjacencyMatrix[indexTail][indexHead] = weight;
            adjacencyMatrix[indexHead][indexTail] = weight; // 无向图
        }

        // 执行Kruskal算法
        kruskalAlgorithm();
    }
};

int main() {
    Map test;
    return 0;
}
