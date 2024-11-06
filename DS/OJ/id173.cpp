#include <iostream>
using namespace std;

class HTNode
{
private:
    char data;
    int weight;
    HTNode *lchild, *rchild;
public:
    HTNode():weight(0), lchild(NULL), rchild(NULL){}
    ~HTNode(){}
    friend class HuffmanTree;
};

class HuffmanTree
{
private:
    HTNode *root;
    int LeafNum;
    string str1;
    int *str2;
public:
    HuffmanTree();
    ~HuffmanTree();
    void CreateTree();
    void CreateTree(HTNode *&p, int &i, int &j);
    void PreOrder();
    void PreOrder(HTNode *p, int Level, int &TotalRoad);
};

HuffmanTree::HuffmanTree()
{
    cin>>str1;
    cin>>LeafNum;
    str2 = new int[LeafNum];
    for(int i=0; i<LeafNum; i++)
        cin>>str2[i];
}

HuffmanTree::~HuffmanTree()
{
    delete root;
    delete []str2;
}

void HuffmanTree::CreateTree(HTNode *&p, int &i, int &j)
{
    if(str1[i]!='0')
    {
        p = new HTNode;
        if(str1[i]>=65 && str1[i]<=90)
        {
            p->data = str1[i];
            p->weight = str2[j];
            j++;
        }
        i++;
        CreateTree(p->lchild, i, j);
        i++;
        CreateTree(p->rchild, i, j);
    }
    else
        p = NULL;
}

void HuffmanTree::CreateTree()
{
    int i = 0;
    int j = 0;
    CreateTree(root, i, j);
}

void HuffmanTree::PreOrder()
{
    int Level = 0;
    int TotalRoad = 0;
    PreOrder(root, Level, TotalRoad);
    cout<<TotalRoad<<endl;
}

void HuffmanTree::PreOrder(HTNode *p, int Level, int &TotalRoad)
{
    if(p)
    {
        if(!p->lchild && !p->rchild)
        {
            TotalRoad += p->weight*Level;
        }
        Level++;
        PreOrder(p->lchild, Level, TotalRoad);
        PreOrder(p->rchild, Level, TotalRoad);
    }
}

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        HuffmanTree myTree;
        myTree.CreateTree();
        myTree.PreOrder();
    }
    return 0;
}
