#include<iostream>
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
        void DFS(int index,int met[]);
    public:
        Graph(int nN = 0,int aN = 0,char gK = 0):
            nodeNum(nN),arcNum(aN),graphKind(gK){}
        void printAdjacencyMatrix();
        void initGraphByAdjacencyMatrix(int nodeNum);
        void DFS();
};
void Graph::DFS()
{
    int met[nodeNum] = {0};
    DFS(0,met);
    cout << endl;
}
void Graph::DFS(int index,int met[])
{
    met[index] = 1;
    cout << index << " ";
    for(int i=0;i<nodeNum;i++)
    {
        if(index == i)
            continue;
        if(adjacencyMatrix[index][i] == 1)
        {
            if(met[i] == 1)
                continue;
            if(met[i] == 0)
                DFS(i,met);
        }
    }
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
        jojo.DFS();
    }

    return 0;
}