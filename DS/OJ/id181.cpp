#include<iostream>
#include<vector>
using namespace std;

struct SonAndParent
{
    char son;
    char parent;
};

class BinaryTree;

class BinaryTreeNode // *LeftChild | Data | *RightChild
{
    private:
        char data; // 节点数据
        BinaryTreeNode* leftChild,*rightChild; 
    public:
        BinaryTreeNode(char e='\0',BinaryTreeNode *l=nullptr,BinaryTreeNode *r=nullptr);
        char GetNode();
        BinaryTreeNode *GetLeftChild();
        BinaryTreeNode *GetRightChild();
        void SetLeftChild(BinaryTreeNode *l);
        void SetRightChild(BinaryTreeNode *r);
};
class BinaryTree
{
    void friend CreateMyBT(BinaryTree &tree);
    private:
        BinaryTreeNode* root;
        BinaryTreeNode *CreateBinaryTree(string s,int &i);
        void PreorderTraverse(BinaryTreeNode* t);
        void PostorderTraverse(BinaryTreeNode* t);
        void InorderTraverse(BinaryTreeNode* t);
        int GetNumberOfLeafNode(BinaryTreeNode* t,BinaryTreeNode* pre,vector<SonAndParent>& sp);
    public:
        BinaryTree();// 置空树
        void CreateBinaryTreeAccordingToPreorderString(string s);
        void PreorderTraverse();
        void PostorderTraverse();
        void InorderTraverse();
        int GetNumberOfLeafNode();
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
    root = CreateBinaryTree(s,i);
}
BinaryTreeNode *BinaryTree::CreateBinaryTree(string s,int &i)
{
    BinaryTreeNode* T = nullptr;
    if(s[i] != '0') 
    {
        T = new BinaryTreeNode(s[i]);
        T->SetLeftChild(CreateBinaryTree(s,++i));
        T->SetRightChild(CreateBinaryTree(s,++i));
    }
    return T;
}
// ---
int BinaryTree::GetNumberOfLeafNode(BinaryTreeNode* t,BinaryTreeNode* pre,vector<SonAndParent>& sp)
{
    if(!t) // 节点存在
        return 0; 
    if(t->GetLeftChild() || t->GetRightChild()) // 节点存在下级节点
        return GetNumberOfLeafNode(t->GetLeftChild(),t,sp) + GetNumberOfLeafNode(t->GetRightChild(),t,sp);
    
    sp.push_back({t->GetNode(),pre->GetNode()});
    return 1; // 剩下的情况即节点不存在下级节点
}
int BinaryTree::GetNumberOfLeafNode()
{
    vector<SonAndParent> sp;
    vector<char> Parent;
    int n = GetNumberOfLeafNode(this->root,nullptr,sp);
    for(int i=0;i<sp.size();i++)
    {
        cout << sp[i].son << " ";
    }
    cout << endl;
    for(int i=0;i<sp.size();i++)
    {
        cout << sp[i].parent << " ";
    }
    cout << endl;

    return n;
}
// ---
int main(){

    int t;
    cin >> t;
    string str;
    while(t--)
    {
        cin >> str;
        BinaryTree tree;
        tree.CreateBinaryTreeAccordingToPreorderString(str);
        tree.GetNumberOfLeafNode();
    }
    
    return 0;
}