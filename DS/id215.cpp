#include <iostream>
#include <queue>
using namespace std;

class Binary_tree_node
{
public:
    char data;                                //数据域
    int weight;                               //结点权重
    Binary_tree_node *LeftChild, *RightChild; //左右孩子
    Binary_tree_node() : LeftChild(NULL), RightChild(NULL) {}
    ~Binary_tree_node()
    {
        delete LeftChild;
        delete RightChild;
    }
};

class Binary_tree
{
public:
    Binary_tree_node *root; //根节点
    queue<int> weights;     //
    int maxRoad;            //最大权重
    Binary_tree() {}
    ~Binary_tree() {}
    //先序创建二叉树
    void CreateTree()
    {
        CreateTree(root);
    }
    void CreateTree(Binary_tree_node *&p)
    {
        char ch;
        cin >> ch;
        if (ch == '0') //结点为空
        {
            p = NULL;
        }
        else //结点不为空
        {
            p = new Binary_tree_node;
            p->data = ch;
            CreateTree(p->LeftChild);
            CreateTree(p->RightChild);
        }
    }
    //获取最大路径权值
    void getRoad()
    {
        int nodes_num;
        cin>>nodes_num;
        while(nodes_num--)
        {
            int num;
            cin>>num;
            weights.push(num);
        }
        getRoad(root,0);
        cout<<maxRoad<<endl;
    }
    void getRoad(Binary_tree_node *p, int road)
    {
        if (p != NULL)              //结点不为空
        {
            p->weight=weights.front()+road;
            weights.pop();
            getRoad(p->LeftChild,p->weight);
            getRoad(p->RightChild,p->weight);
            
            if(!p->LeftChild&&!p->RightChild)
            {
                if(p->weight>maxRoad)
                {
                    maxRoad=p->weight;
                }
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Binary_tree Bt;
        Bt.CreateTree();
        Bt.getRoad();
    }
    return 0;
}
