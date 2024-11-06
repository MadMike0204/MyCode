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
        string getVertexName()
        {
            return vertex;
        }
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
        int** adjacencyMatrix;
    public:
        Graph(int nN = 0,int aN = 0,char gK = 0):
            nodeNum(nN),arcNum(aN),graphKind(gK){}
        void resetParameter(int nodeNum,int arcNum,char graphKind);
        int initGraph();
        void initVertexes();
        void initArcs();
        void printAdjacencyTable();
        void createGraphAdjacencyMatrix();
        void createDigraphAdjacencyMatrix();
        void createUndigraphAdjacencyMatrix();
        void printAdjacencyMatrix();
        void printDegree();
        void printVertex();
};
void Graph::printDegree()
{
    int outDegree[nodeNum];
    int inDegree[nodeNum];
    for(int i=0;i<nodeNum;i++)
    {
        outDegree[i] = 0;
        inDegree[i] = 0;
    }
    for(int i=0;i<nodeNum;i++)
    {
        for(int j=0;j<nodeNum;j++)
        {
            if(adjacencyMatrix[i][j])
            {
                outDegree[i]++;
                inDegree[j]++;
            }
        }
    }

    string vertexName;
    if(graphKind == 'D')
    {
        int sum;
        for(int i=0;i<nodeNum;i++)
        {
            vertexName = nodes[i].getVertexName();
            sum = inDegree[i] + outDegree[i];
            if(!sum)
            {
                cout << vertexName << endl;
                continue;
            }
            cout << vertexName << ": " 
                 << outDegree[i] << " " 
                 << inDegree[i] << " "
                 << outDegree[i] + inDegree[i]
                 << endl;
        }
        return;
    }

    for(int i=0;i<nodeNum;i++)
    {
        vertexName = nodes[i].getVertexName();
        if(!outDegree[i])
        {
            cout << vertexName << endl;
            continue;
        }
        cout << vertexName << ": "
             << outDegree[i] << endl;
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
void Graph::createDigraphAdjacencyMatrix()
{
    adjacencyMatrix = new int*[nodeNum];
    for(int i=0;i<nodeNum;i++)
    {
        adjacencyMatrix[i] = new int[nodeNum];
        for(int j=0;j<nodeNum;j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for(int i=0;i<nodeNum;i++)
    {
        ArcNode* currentArc = nodes[i].headArc;
        while(true)
        {
            if(currentArc == nullptr)
                break;
            adjacencyMatrix[i][currentArc->adjacentVertex] = 1;
            currentArc = currentArc->nextArc;
        }
    }
}
void Graph::createUndigraphAdjacencyMatrix()
{
    adjacencyMatrix = new int*[nodeNum];
    for(int i=0;i<nodeNum;i++)
    {
        adjacencyMatrix[i] = new int[nodeNum];
        for(int j=0;j<nodeNum;j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for(int i=0;i<nodeNum;i++)
    {
        ArcNode* currentArc = nodes[i].headArc;
        while(true)
        {
            if(currentArc == nullptr)
                break;
            adjacencyMatrix[i][currentArc->adjacentVertex] = 1;
            adjacencyMatrix[currentArc->adjacentVertex][i] = 1;
            currentArc = currentArc->nextArc;
        }
    }
}
void Graph::createGraphAdjacencyMatrix()
{
    if(graphKind == 'D')
        createDigraphAdjacencyMatrix();
    else if(graphKind == 'U')
        createUndigraphAdjacencyMatrix();
}
void Graph::resetParameter(int nodeNum,int arcNum,char graphKind)
{
    this->nodeNum = nodeNum;
    this->arcNum = arcNum;
    this->graphKind = graphKind;
}
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
void Graph::printVertex()
{
    for(int i=0;i<nodeNum;i++)
    {
        cout << nodes[i].vertex << endl;
    }
}

int main(){

    int t;
    char type = 'D';
    cin >> t;
    int node,arc;
    while(t--)
    {
        cin >> type >> node;
        Graph jojo(node,arc,type);
        jojo.initVertexes();
        cin >> arc;
        jojo.resetParameter(node,arc,type);
        jojo.initArcs();
        jojo.createGraphAdjacencyMatrix();
        jojo.printAdjacencyMatrix();
        jojo.printDegree();
    }

    return 0;
}