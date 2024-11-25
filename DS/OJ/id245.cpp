#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Vertex {
public:
    int indexNo;
    bool hasEnterQueue;
    int early;
    int later;

    Vertex(int indexNo) {
        this->indexNo = indexNo;
        this->hasEnterQueue = false;
        early = -1;
        later = 0x7FFFF;
    }
    void updateEarly(int parentEarly, int edgeValue) {
        int newEarly = parentEarly + edgeValue;
        if (newEarly > this->early)
            this->early = newEarly;
    }
    void updateLater(int childLater, int edgeValue) {
        int newLater = childLater - edgeValue;
        if (newLater < this->later)
            this->later = newLater;
    }
};

class Graph {
public:
    vector<Vertex> vertexes;
    vector<vector<int>> adjMat;
    int n;

public:
    void readVertexes() {
        // 读取顶点数并初始化
        cin >> n;

        // 初始化 vertexes
        for (int i = 0; i < n; ++i) {
            Vertex v(i);
            this->vertexes.push_back(v);
        }

        // 初始化 adjMat
        for (int i = 0; i < n; ++i) {
            vector<int> row;
            for (int j = 0; j < n; ++j) {
                row.push_back(0); // 所有边初始为0
            }
            adjMat.push_back(row);
        }
    }

    void readAdjMatrix() {
        // 读取边数
        int edges;
        cin >> edges;
        for (int i = 0; i < edges; ++i) {
            int s, t, w;  // s源顶点编号, t目的顶点编号, w边长
            cin >> s >> t >> w;
            adjMat[s][t] = w; // 更新邻接矩阵
        }
    }

    void updateEarly(int parentNo, queue<int>& earlyQue) {
        int parentEarly = vertexes[parentNo].early;

        for (int j = 0; j < n; ++j) {
            int edgeValue = adjMat[parentNo][j];
            if (edgeValue == 0) continue;

            Vertex& child = vertexes[j];
            child.updateEarly(parentEarly, edgeValue);

            if (!child.hasEnterQueue) {
                child.hasEnterQueue = true;
                earlyQue.push(j);
            }
        }
    }

    void updateLater(int childNo, queue<int>& laterQue) {
        int childLater = vertexes[childNo].later;

        for (int i = 0; i < n; ++i) {
            int edgeValue = adjMat[i][childNo];
            if (edgeValue == 0) continue;

            Vertex& parent = vertexes[i];
            parent.updateLater(childLater, edgeValue);

            if (!parent.hasEnterQueue) {
                parent.hasEnterQueue = true;
                laterQue.push(i);
            }
        }
    }

    int getRoot() {
        // 找到入度为0的顶点
        for (int j = 0; j < n; ++j) {
            int i = 0;
            for (; i < n && adjMat[i][j] == 0; ++i);
            if (i >= n) return j; // j没有入边
        }
        return -1;
    }

    int getLeaf() {
        // 找到出度为0的顶点
        for (int i = 0; i < n; ++i) {
            int j = 0;
            for (; j < n && adjMat[i][j] == 0; ++j);
            if (j >= n) return i; // i没有出边
        }
        return -1;
    }

    void printEarlyLater(bool isEarly) {
        for (int i = 0; i < n; ++i) {
            Vertex& v = vertexes[i];
            if (isEarly)
                cout << v.early << " ";
            else
                cout << v.later << " ";
        }
        cout << endl;
    }

    void findEarly() {
        int r = getRoot();
        Vertex& root = vertexes[r];
        root.hasEnterQueue = true;
        root.early = 0;

        queue<int> que;
        que.push(r);

        while (!que.empty()) {
            int p = que.front();
            que.pop();

            updateEarly(p, que);
        }

        printEarlyLater(true);
    }

    void clearEnterQueue() {
        for (int i = 0; i < n; ++i) {
            vertexes[i].hasEnterQueue = false;
        }
    }

    void findLater() {
        clearEnterQueue();

        int l = getLeaf();
        Vertex& leaf = vertexes[l];
        leaf.hasEnterQueue = true;
        leaf.later = leaf.early;

        queue<int> que;
        que.push(l);

        while (!que.empty()) {
            int c = que.front();
            que.pop();

            updateLater(c, que);
        }

        printEarlyLater(false);
    }

    void main() {
        readVertexes();
        readAdjMatrix();
        findEarly();
        findLater();
    }
};

int main() {
    int t = 1;
    while (t--) {
        Graph g;
        g.main();
    }
    return 0;
}
