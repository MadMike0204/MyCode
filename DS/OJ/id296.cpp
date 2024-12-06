#include<iostream>
#define ENDKEY 65535
using namespace std;
class BinaryTree;

class BinaryTreeNode //二叉树节点定义 *LeftChild | Data | *RightChild
{
    friend class BinaryTree;
    private:
        int data; // 存放节点数据
        BinaryTreeNode* leftChild,*rightChild;// 左子树和右子树
    public:
        BinaryTreeNode(int e=0,BinaryTreeNode *l=nullptr,BinaryTreeNode *r=nullptr); // 初始化节点
        int GetNode(); // 获取节点数据
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
        void InsertBST(BinaryTreeNode *&T,int key); // 插入
        BinaryTreeNode* BSTSearch(BinaryTreeNode* T, int key, int& count);
    public:
        BinaryTree();// 置空树
        void CreateBinaryTreeAccordingToPreorderString(string s); // 根据先序字符串创建二叉树 入口
        void PreorderTraverse(); // 先序 输出二叉树 入口
        void PostorderTraverse();// 后序 输出二叉树 入口
        void InorderTraverse();  // 中序 输出二叉树 入口
        int BSTSearch(int key);
        void InsertBST(int key); // 插入 入口
        void CreateBST();
};

// --- BinaryTreeNode类的方法实现
int BinaryTree::BSTSearch(int key) {
    int count = 0;
    BinaryTreeNode* result = BSTSearch(root, key, count);
    if (result) {
        return count; // 返回查找次数
    } else {
        return -1; // 未找到
    }
}

BinaryTreeNode* BinaryTree::BSTSearch(BinaryTreeNode* T, int key, int& count) {
    if (T == nullptr) {
        return nullptr; // 未找到
    }
    count++; // 每次递归增加查找次数
    if (key == T->GetNode()) {
        return T; // 找到目标值
    } else if (key < T->GetNode()) {
        return BSTSearch(T->GetLeftChild(), key, count);
    } else {
        return BSTSearch(T->GetRightChild(), key, count);
    }
}

void BinaryTree::CreateBST()
{
    int key;
    BinaryTreeNode *T = new BinaryTreeNode;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> key;
        InsertBST(T,key);
    }
    root = T;
}
void BinaryTree::InsertBST(int key)
{
    InsertBST(root,key);
}
void BinaryTree::InsertBST(BinaryTreeNode *&T, int key) {
    if (T == nullptr) {
        T = new BinaryTreeNode(key);
    } else {
        if (key == T->GetNode())    
            return; // 已存在对应数据的节点
        else if (key < T->GetNode())
            InsertBST(T->leftChild, key);
        else
            InsertBST(T->rightChild, key);
    }
}

BinaryTreeNode::BinaryTreeNode(int e,BinaryTreeNode* l,BinaryTreeNode* r):
    data(e),leftChild(l),rightChild(r)
{}
int BinaryTreeNode::GetNode()
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
    if(node != root)
        cout << node->GetNode() << " ";
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
    if(node != root)
        cout << node->GetNode() << " ";
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

    BinaryTree jojo;
    jojo.CreateBST();
    jojo.InorderTraverse();
    int n,key;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> key;
        int result = jojo.BSTSearch(key);
        if(result != -1)
            result --;
        cout << result << endl;
    }
    
    return 0;
}