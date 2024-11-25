#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX // 定义无穷大为标准库最大值

class Graph {
private:
    int vertexCount;                   // 顶点数量
    vector<vector<int>> adjacency;    // 邻接矩阵
    vector<string> vertices;          // 存放顶点的名称
    string startVertex;               // 起始顶点名称
    vector<string> paths;             // 最短路径字符串记录

    // 查找顶点名称对应的索引
    int getVertexIndex(const string& vertex) const {
        for (int i = 0; i < vertexCount; ++i) {
            if (vertex == vertices[i]) {
                return i;
            }
        }
        return -1;
    }

public:
    // 构造函数：从输入流中读取图的数据
    Graph() {
        cin >> vertexCount;

        vertices.resize(vertexCount);
        adjacency.assign(vertexCount, vector<int>(vertexCount, INF));
        paths.resize(vertexCount);

        // 读取顶点名称
        for (int i = 0; i < vertexCount; ++i) {
            cin >> vertices[i];
        }

        // 读取邻接矩阵
        for (int i = 0; i < vertexCount; ++i) {
            for (int j = 0; j < vertexCount; ++j) {
                cin >> adjacency[i][j];
                if (adjacency[i][j] == 0 && i != j) {
                    adjacency[i][j] = INF; // 无边的情况设置为INF
                }
            }
        }

        // 读取起始顶点名称
        cin >> startVertex;
    }

    // Dijkstra算法实现
    void Dijkstra() {
        vector<bool> finalized(vertexCount, false); // 标记顶点是否已确定最短路径
        vector<int> distances(vertexCount, INF);   // 存储最短路径的距离
        int startIndex = getVertexIndex(startVertex);

        // 初始化
        for (int i = 0; i < vertexCount; ++i) {
            paths[i] = startVertex + " ";
            distances[i] = adjacency[startIndex][i];
        }
        distances[startIndex] = 0;  // 起始点距离为0
        finalized[startIndex] = true;

        // 迭代计算最短路径
        for (int i = 0; i < vertexCount - 1; ++i) {
            int minDistance = INF;
            int currentVertex = -1;

            // 找到未处理顶点中距离最小的顶点
            for (int j = 0; j < vertexCount; ++j) {
                if (!finalized[j] && distances[j] < minDistance) {
                    minDistance = distances[j];
                    currentVertex = j;
                }
            }

            if (currentVertex != -1) {
                finalized[currentVertex] = true;
                paths[currentVertex] += vertices[currentVertex] + " ";

                // 松弛操作
                for (int k = 0; k < vertexCount; ++k) {
                    if (!finalized[k] && adjacency[currentVertex][k] != INF &&
                        minDistance + adjacency[currentVertex][k] < distances[k]) {
                        distances[k] = minDistance + adjacency[currentVertex][k];
                        paths[k] = paths[currentVertex];
                    }
                }
            }
        }

        // 输出结果
        for (int i = 0; i < vertexCount; ++i) {
            if (i == startIndex) continue; // 跳过起始点自身的输出
            cout << startVertex << "-" << vertices[i];
            if (distances[i] == INF) {
                cout << "--1" << endl; // 输出不可达情况
            } else {
                cout << "-" << distances[i] << "----[" << paths[i] << "]" << endl;
            }
        }
    }
};

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        Graph graph;
        graph.Dijkstra();
    }

    return 0;
}
