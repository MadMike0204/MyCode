#include<iostream>
#include<queue>
using namespace std;
#define MAXNODE 20
class Graph;
class VertexNode;

class ArcNode
{
    friend class VertexNode;
    friend class Graph;
    private:
        int adjacentVertex; // 邻接点index
        int weight;
        ArcNode* nextArc;
    public:
        ArcNode(int n = -1,int w = 0,ArcNode* nA = nullptr): // 网生成
            adjacentVertex(n),weight(w),nextArc(nA){}
};
class VertexNode
{
    friend class Graph;
    private:
        string vertex; // 顶点名称
        ArcNode* headArc; // 邻接表头
    public:
        VertexNode(string d = "",ArcNode* hA = nullptr):
            vertex(d),headArc(hA){}
};
class Graph
{
    private:
        VertexNode nodes[MAXNODE];
        int nodeNum;
        int arcNum;
        char graphKind; // 'U' = graph 'D' = digraph
        int getVertexIndexByName(string);
        int** adjacencyMatrix;
    public:
        Graph(int nN = 0,int aN = 0,char gK = 0):
            nodeNum(nN),arcNum(aN),graphKind(gK){}
        void printAdjacencyMatrix();
        void initGraphByAdjacencyMatrix(int nodeNum);
   
        void BFS();
};
void Graph::BFS()
{
    int met[nodeNum] = {0};
    queue<int> q;

    for(int i = 0;i < nodeNum;i++)
    {
        if(met[i] == 0) // 用外循环检查非连通图的孤立结点
        {
            q.push(i);
            met[i] = 1;

            while(!q.empty()) // 重复的队列操作 
            {
                int currentNode = q.front(); // 队首出队，打印，表示遍历到
                q.pop();
                cout << currentNode << " ";
                        // 找当前遍历到的节点的相关节点，让他们入队
                for(int j = 0;j < nodeNum;j++) 
                {
                    if(adjacencyMatrix[currentNode][j] == 1 && met[j] == 0)
                    {
                        q.push(j);
                        met[j] = 1;
                    }
                }
            }
        }
    }
    cout << endl;
}

void Graph::initGraphByAdjacencyMatrix(int nodeNum)
{   
    this->nodeNum = nodeNum;
    adjacencyMatrix = new int*[nodeNum];
    for(int i=0;i<nodeNum;i++)
    {
        adjacencyMatrix[i] = new int[nodeNum];
    }
    for(int i=0;i<nodeNum;i++)
    {
        for(int j=0;j<nodeNum;j++)
        {
            cin >> adjacencyMatrix[i][j];
        }
    }
}
void Graph::printAdjacencyMatrix()
{
    for(int i=0;i<nodeNum;i++)
    {
        for(int j=0;j<nodeNum;j++)
        {
            printf(j==0?"%d":" %d",adjacencyMatrix[i][j]);
        }
        cout << endl;
    }
}

int main(){

    int t;
    cin >> t;
    int node;
    while(t--)
    {
        cin >> node;
        Graph jojo;
        jojo.initGraphByAdjacencyMatrix(node);
        jojo.BFS();
    }

    return 0;
}