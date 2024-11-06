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
        ArcNode* getNewArc()
        {
            ArcNode* currentArc = headArc;
            while(true)
            {
                if(currentArc == nullptr)
                    break;
                currentArc = currentArc->nextArc;
            }
            currentArc = new ArcNode();
            return currentArc;
        }
        void addAdjcentVertex(int index)
        {
            ArcNode* a = getNewArc();
            a->adjcentVertex = index;
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
        void printGraph();
};
void Graph::printGraph()
{
    for(int i=0;i<nodeNum;i++)
    {
        cout << nodes[i].vertex << " ";
    }
}
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
    initVertexes();
    initArcs();
    return 1;
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
        nodes[indexFormer].addAdjcentVertex(indexLater);
    }
}

void test()
{
    int nodeNum = 5,arcNum = 7,graphKind = 1;
    Graph jojo(nodeNum,arcNum,graphKind);
    jojo.initGraph();
    jojo.printGraph();
}

int main(){

    test();

    return 0;
}