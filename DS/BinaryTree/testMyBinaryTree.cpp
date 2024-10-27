#include<iostream>
using namespace std;
class BinaryTree;

class BinaryTreeNode //二叉树节点定义 *LeftChild | Data | *RightChild
{
    private:
        char data; // 存放节点数据
        BinaryTreeNode* leftChild,*rightChild;// 左子树和右子树
    public:
        BinaryTreeNode(char e='\0',BinaryTreeNode *l=nullptr,BinaryTreeNode *r=nullptr); // 初始化节点
        char GetNode(); // 获取节点数据
        BinaryTreeNode *GetLeftChild(); // 获取指向左子树的指针
        BinaryTreeNode *GetRightChild(); // 获取指向右子树的指针
        void SetLeftChild(BinaryTreeNode *l); // 设置指向左子树的指针
        void SetRightChild(BinaryTreeNode *r); // 设置指向右子树的指针
};

class BinaryTree // 二叉树定义
{
    private:
        BinaryTreeNode* root; // 二叉树树根
        // 输入实例: AB#C##D##
        BinaryTreeNode *CreateBinaryTreeAccordingToPreorderString(string s,int &i); // 根据 先序 递归创建二叉树
        void PreorderTraverse(BinaryTreeNode* t);  // 先序 输出二叉树
        void PostorderTraverse(BinaryTreeNode* t); // 后序 输出二叉树
        void InorderTraverse(BinaryTreeNode* t);   // 中序 输出二叉树
    public:
        BinaryTree();// 置空树
        void CreateBinaryTreeAccordingToPreorderString(string s); // 根据先序字符串创建二叉树 入口
        void PreorderTraverse(); // 先序 输出二叉树 入口
        void PostorderTraverse();// 后序 输出二叉树 入口
        void InorderTraverse();  // 中序 输出二叉树 入口
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
void BinaryTree::PreorderTraverse(BinaryTreeNode* node)
{
    if(!node)
        return;

    cout << node->GetNode();
    PreorderTraverse(node->GetLeftChild());
    PreorderTraverse(node->GetRightChild());
}
void BinaryTree::PreorderTraverse()
{
    PreorderTraverse(this->root);
    cout << endl;
}
// ---
void BinaryTree::InorderTraverse(BinaryTreeNode* node)
{
    if(!node)
        return;

    InorderTraverse(node->GetLeftChild());
    cout << node->GetNode();
    InorderTraverse(node->GetRightChild());
}
void BinaryTree::InorderTraverse()
{
    InorderTraverse(this->root);
    cout << endl;
}
// ---
void BinaryTree::PostorderTraverse(BinaryTreeNode* node)
{
    if(!node)
        return;

    PostorderTraverse(node->GetLeftChild());
    PostorderTraverse(node->GetRightChild());
    cout << node->GetNode();
}
void BinaryTree::PostorderTraverse()
{
    PostorderTraverse(this->root);
    cout << endl;
}
// ---

void BinaryTree::CreateBinaryTreeAccordingToPreorderString(string s)
{
    int i=0;
    root = CreateBinaryTreeAccordingToPreorderString(s,i);
}
BinaryTreeNode *BinaryTree::CreateBinaryTreeAccordingToPreorderString(string s,int &i)
{
    BinaryTreeNode* T = nullptr;
    if(s[i] != '#') 
    {
        T = new BinaryTreeNode(s[i]);
        T->SetLeftChild(CreateBinaryTreeAccordingToPreorderString(s,++i));
        T->SetRightChild(CreateBinaryTreeAccordingToPreorderString(s,++i));
    }
    return T;
}

int main(){

    string str;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> str;
        BinaryTree tree;
        tree.CreateBinaryTreeAccordingToPreorderString(str);
        tree.PreorderTraverse();
        tree.InorderTraverse();
        tree.PostorderTraverse();
    }
    
    return 0;
}