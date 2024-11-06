#include<iostream>
using namespace std;
#define MAXNODE 100
class Graph;
class VertexNode;

class ArcNode
{
    friend class VertexNode;
    private:
        int adjcentVertex; // 邻接点index
        int weight;
        ArcNode* nextArc;
    public:
        ArcNode(int n = -1,int w = 0,ArcNode* nA = nullptr): // 网生成
            adjcentVertex(n),weight(w),nextArc(nA){}
        ArcNode(int n = -1,ArcNode* nA = nullptr): // 图生成
            adjcentVertex(n),nextArc(nA){}
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
        ArcNode* getLastArc()
        {
            ArcNode* currentArc = headArc;
            while(currentArc->nextArc != nullptr)
            {
                currentArc = currentArc->nextArc;
            }
            return currentArc;
        }
        void addAdjcentVertex(int index)
        {
            ArcNode* a = getLastArc();
            a->adjcentVertex = index;
        }
};
class Graph
{
    private:
        VertexNode nodes[MAXNODE];
        int nodeNum;
        int arcNum;
        int graphKind; // 'U' = graph 'D' = digraph
        int getVertexIndexByName(string);
    public:
        Graph(int nN = 0,int aN = 0,int gK = 0):
            nodeNum(nN),arcNum(aN),graphKind(gK){}
        int initGraph();
        void initVertexes();
        void initArcs();
};
int Graph::getVertexIndexByName(string v)
{
    for(int i=0;i<nodeNum;++i)
    {
        if(v == nodes[i].vertex)
            return i;
    }
    return -1;
}
int Graph::initGraph()
{
    cin >> graphKind;
    cin >> nodeNum;
    initVertexes();
    cin >> arcNum;
    initArcs();
}
void Graph::initVertexes()
{
    string vertex;
    for(int i=0;i<nodeNum;++i)
    {
        cin >> nodes[i].vertex;
    }
}
void Graph::initArcs()
{
    string vertexFormer,vertexLater;
    for(int i=0;i<arcNum;++i)
    {
        cin >> vertexFormer >> vertexLater;
        int indexFormer = getVertexIndexByName(vertexFormer);
        int indexLater = getVertexIndexByName(vertexLater);
        
    }
}