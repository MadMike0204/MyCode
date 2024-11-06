#include<iostream>
using namespace std;
#define MAXNODE 100
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
        void addAdjacentVertex(int index)
        {
            if(headArc == nullptr)
            {
                headArc = new ArcNode();
                headArc->adjacentVertex = index;
                return;
            }
            ArcNode* currentArc = headArc;
            while(true)
            {
                if(currentArc->nextArc == nullptr)
                    break;
                currentArc = currentArc->nextArc;
            }
            currentArc->nextArc = new ArcNode();
            currentArc->nextArc->adjacentVertex = index;
            return;
        }
};
class Graph
{
    private:
        VertexNode nodes[MAXNODE];
        int nodeNum;
        int arcNum;
        char graphKind; // 'U' = graph 'D' = digraph
        int getVertexIndexByName(string);
    public:
        Graph(int nN = 0,int aN = 0,char gK = 0):
            nodeNum(nN),arcNum(aN),graphKind(gK){}
        int initGraph();
        void initVertexes();
        void initArcs();
        void printAdjacencyTable();
};
void Graph::printAdjacencyTable()
{
    for(int i=0;i<nodeNum;i++)
    {
        cout << i << " " << nodes[i].vertex << "-";
        ArcNode* currentNode = nodes[i].headArc;
        while(currentNode != nullptr)
        {
            cout << currentNode->adjacentVertex << "-";
            currentNode = currentNode->nextArc;
        }
        cout << "^" << endl;
    }
}
int Graph::getVertexIndexByName(string v)
{
    for(int i=0;i<nodeNum;i++)
    {
        if(v == nodes[i].vertex)
            return i;
    }
    return -1;
}
int Graph::initGraph()
{
    initVertexes();
    initArcs();
    return 1;
}
void Graph::initVertexes()
{
    string vertex;
    for(int i=0;i<nodeNum;i++)
    {
        cin >> nodes[i].vertex;
    }
}
void Graph::initArcs()
{
    string vertexFormer,vertexLater;
    for(int i=0;i<arcNum;i++)
    {
        cin >> vertexFormer >> vertexLater;
        int indexFormer = getVertexIndexByName(vertexFormer);
        int indexLater = getVertexIndexByName(vertexLater);
        nodes[indexFormer].addAdjacentVertex(indexLater);
    }
}

int main(){

    int t;
    char type = 'D';
    cin >> t;
    int node,arc;
    while(t--)
    {
        cin >> node >> arc;
        Graph jojo(node,arc,type);
        jojo.initGraph();
        jojo.printAdjacencyTable();
    }

    return 0;
}