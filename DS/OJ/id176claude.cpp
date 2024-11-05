#include <iostream>
#include <cstring>
using namespace std;

class TreeNode
{
    private:
        int leftChild;
        int rightChild;
        int nodeWeight;
        int parentIndex;
    
    public:
        TreeNode();
        ~TreeNode();
        friend class HuffmanTree;
};

TreeNode::TreeNode()
{
    leftChild = 0;
    rightChild = 0;
    nodeWeight = 0;
    parentIndex = 0;
}

TreeNode::~TreeNode()
{
    leftChild = 0;
    rightChild = 0;
    nodeWeight = 0;
    parentIndex = 0;
}

class HuffmanTree
{
    private:
        TreeNode* treeNodes;
        string* huffmanCode;
        const int MAX_WEIGHT = 10000;
        int treeSize;
        int leafNum;
        
        void BuildTree();
        void FindTwoMinimum(int currentPos, int* firstMin, int* secondMin);
        
    public:
        HuffmanTree();
        ~HuffmanTree();
        void InitializeTree(int nodeNum, int* weights);
        void GenerateHuffmanCode();
        void PrintNodeInfo(int index);
        int GetLeafNum() { return leafNum; }
};

HuffmanTree::HuffmanTree()
{
    treeNodes = nullptr;
    huffmanCode = nullptr;
    treeSize = 0;
    leafNum = 0;
}

HuffmanTree::~HuffmanTree()
{
    if(treeNodes != nullptr)
    {
        delete[] treeNodes;
        treeNodes = nullptr;
    }
    if(huffmanCode != nullptr)
    {
        delete[] huffmanCode;
        huffmanCode = nullptr;
    }
}

void HuffmanTree::BuildTree()
{
    for(int i = leafNum + 1; i <= treeSize; i++)
    {
        int firstMin, secondMin;
        FindTwoMinimum(i - 1, &firstMin, &secondMin);
        
        treeNodes[firstMin].parentIndex = treeNodes[secondMin].parentIndex = i;
        treeNodes[i].leftChild = firstMin;
        treeNodes[i].rightChild = secondMin;
        treeNodes[i].nodeWeight = treeNodes[firstMin].nodeWeight + treeNodes[secondMin].nodeWeight;
    }
}

void HuffmanTree::InitializeTree(int nodeNum, int* weights)
{
    leafNum = nodeNum;
    treeSize = 2 * nodeNum - 1;
    
    // 分配内存
    treeNodes = new TreeNode[treeSize + 1];
    huffmanCode = new string[leafNum + 1];
    
    // 初始化叶节点权重
    for(int i = 1; i <= nodeNum; i++)
    {
        treeNodes[i].nodeWeight = weights[i - 1];
    }
    
    BuildTree();
}

void HuffmanTree::FindTwoMinimum(int currentPos, int* firstMin, int* secondMin)
{
    int weight1, weight2;
    weight1 = weight2 = MAX_WEIGHT;
    *firstMin = *secondMin = 0;
    
    for(int i = 1; i <= currentPos; i++)
    {
        if(treeNodes[i].parentIndex == 0)
        {
            if(weight1 > treeNodes[i].nodeWeight)
            {
                weight2 = weight1;
                *secondMin = *firstMin;
                weight1 = treeNodes[i].nodeWeight;
                *firstMin = i;
            }
            else if(weight2 > treeNodes[i].nodeWeight)
            {
                weight2 = treeNodes[i].nodeWeight;
                *secondMin = i;
            }
        }
    }
}

void HuffmanTree::GenerateHuffmanCode()
{
    char* tempCode = new char[leafNum];
    tempCode[leafNum - 1] = '\0';
    
    for(int i = 1; i <= leafNum; i++)
    {
        int start = leafNum - 1;
        int child = i;
        int parent = treeNodes[i].parentIndex;
        
        while(parent != 0)
        {
            if(treeNodes[parent].leftChild == child)
            {
                tempCode[--start] = '0';
            }
            else
            {
                tempCode[--start] = '1';
            }
            child = parent;
            parent = treeNodes[parent].parentIndex;
        }
        
        huffmanCode[i].assign(&tempCode[start]);
    }
    
    delete[] tempCode;
}

void HuffmanTree::PrintNodeInfo(int index)
{
    cout << treeNodes[index].nodeWeight << "-" << huffmanCode[index] << endl;
}

int main()
{
    int testCases = 1;
    
    while(testCases--)
    {
        int nodeCount;
        cin >> nodeCount;
        
        int* weights = new int[nodeCount];
        for(int i = 0; i < nodeCount; i++)
        {
            cin >> weights[i];
        }
        
        HuffmanTree huffman;
        huffman.InitializeTree(nodeCount, weights);
        huffman.GenerateHuffmanCode();
        
        for(int i = 1; i <= huffman.GetLeafNum(); i++)
        {
            huffman.PrintNodeInfo(i);
        }
        
        delete[] weights;
    }
    
    return 0;
}