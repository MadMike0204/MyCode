#include <iostream>
#include <vector>

using namespace std;

class Map {
    vector<vector<int>> matrix; // 邻接矩阵
    vector<bool> visited;       // 标记是否访问
    int numVertices;            // 顶点数量

    int findVertexWithZeroIndegree() {
        // 查找入度为0且未访问的顶点
        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v]) {
                bool hasIndegree = false;
                for (int i = 0; i < numVertices; ++i) {
                    if (matrix[i][v] != 0) { // 存在入度
                        hasIndegree = true;
                        break;
                    }
                }
                if (!hasIndegree) { // 入度为0且未访问
                    return v;
                }
            }
        }
        return -1; // 未找到
    }

public:
    Map() {
        cin >> numVertices;
        matrix.resize(numVertices, vector<int>(numVertices));
        visited.resize(numVertices, false);

        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cin >> matrix[i][j];
            }
        }
    }

    void topoSort() {
        for (int i = 0; i < numVertices; ++i) {
            int vertex = findVertexWithZeroIndegree();
            if (vertex == -1) {
                cerr << "Error: Cycle detected in the graph!" << endl;
                return;
            }
            visited[vertex] = true; // 标记为已访问
            cout << vertex << " "; // 输出顶点

            // 将矩阵中对应顶点的出边清零
            for (int j = 0; j < numVertices; ++j) {
                matrix[vertex][j] = 0;
            }
        }
        cout << endl;
    }
};

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        Map m;
        m.topoSort();
    }
    return 0;
}
