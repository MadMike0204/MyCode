#include <iostream>
using namespace std;

class BinaryTreeNode // *LeftChild | Data | *RightChild
{
    private:
        char data; // 节点数据
        BinaryTreeNode* leftChild,*rightChild; 
    public:
        BinaryTreeNode(char e,BinaryTreeNode *l=nullptr,BinaryTreeNode *r=nullptr);
        char GetNode();
        BinaryTreeNode *GetLeftChild();
        BinaryTreeNode *GetRightChild();
        void SetLeftChild(BinaryTreeNode *l);
        void SetRightChild(BinaryTreeNode *r);
};
class BinaryTree
{
    private:
        BinaryTreeNode* root;
    public:
        BinaryTree();// 置空树
};
// --- BinaryTreeNode类的方法实现
BinaryTreeNode::BinaryTreeNode(char e,BinaryTreeNode* l,BinaryTreeNode* r):
    data(e),leftChild(l),rightChild(r)
{}
char BinaryTreeNode::GetNode()
{
    return data;
}
BinaryTreeNode* BinaryTreeNode::GetLeftChild()
{
    return leftChild;
}
BinaryTreeNode* BinaryTreeNode::GetRightChild()
{
    return rightChild;
}
void BinaryTreeNode::SetLeftChild(BinaryTreeNode* l)
{
    leftChild = l;
}
void BinaryTreeNode::SetRightChild(BinaryTreeNode* r)
{
    rightChild = r;
}
// --- BinaryTree类的方法实现
BinaryTree::BinaryTree()
{
    root = nullptr;
}

int main(){


    return 0;
}