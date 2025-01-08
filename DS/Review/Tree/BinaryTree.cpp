#include<iostream>
#include<vector>
using namespace std;

string sTree; //建树字符串sTree;
int pos;      //建树字符串的当前字符位置
int count;    //结点生成数量

struct FatherChild{
    char father;
    char child;
};

struct BiTreeNode {
    char data; //数据域
    BiTreeNode  *leftChild,  *rightChild; //左右子树指针
};

BiTreeNode * BTree_Create(); //输入建树字符串并构建二叉树
BiTreeNode* BTree_CreateNode(); //建树操作函数，递归操作
void BTree_pre_order(BiTreeNode*); //先序遍历，递归操作函数
void BTree_in_order(BiTreeNode*); //中序遍历，递归操作函数
void BTree_post_order(BiTreeNode*); //后序遍历，递归操作函数
void BTree_PC_pre(BiTreeNode* root, char parent,vector<FatherChild> &relations);
BiTreeNode* buildTree(
    const string& preorder,
    const string& inorder,
    int preStart,
    int preEnd,
    int inStart,
    int inEnd
);
BiTreeNode* BTree_Create_pre_in(
    const string& preorder,
    const string& inorder
);

void xbuildTree();
void id378();
void id183();
void id181();

int main(){

    id181();

    return 0;
}
BiTreeNode* buildTree(
    const string& preorder,
    const string& inorder,
    int preStart,
    int preEnd,
    int inStart,
    int inEnd
){
    if(preStart > preEnd || inStart > inEnd)
        return NULL;
    // 先序第一个节点 是 root
    char rootValue = preorder[preStart];
    BiTreeNode* root = new BiTreeNode{rootValue,NULL,NULL};

    // 中序中找根节点
    int rootIndex = inStart;
    while(rootIndex <= inEnd && inorder[rootIndex] != rootValue){
        rootIndex++;
    }
    // 左子树节点数量
    int leftSize = rootIndex-inStart;
    // 构造左子树
    root->leftChild = buildTree(preorder,inorder,preStart+1,preStart+leftSize,inStart,rootIndex-1);
    // 构造右子树
    root->rightChild = buildTree(preorder,inorder,preStart+leftSize+1,preEnd,rootIndex+1,inEnd);

    return root;
}
BiTreeNode* BTree_Create_pre_in(const string& preorder,const string& inorder){

}
BiTreeNode * BTree_Create() {
    cin >> sTree; //输入建树字符串
    count=0;
    pos=0; //从建树字符串的位置0开始
    return BTree_CreateNode(); //建树成功后返回根结点指针
}
BiTreeNode* BTree_CreateNode(){
    if(pos >= sTree.size()){ // 如果已经遍历完了 (i >= length)
        return NULL;
    }

    char ch = sTree[pos++]; // 先返回当前字符 计数器再自增
    if(ch == '0'){ // 这里的空节点用'0'表示 读到0 就返回
        return NULL;
    }

    // 新建节点
    BiTreeNode* node = new BiTreeNode; 
    node->data = ch; // 数据用当前字符
    count++; // 统计节点数
    node->leftChild = BTree_CreateNode();
    node->rightChild = BTree_CreateNode();

    return node;
}
void BTree_pre_order(BiTreeNode* root){
    if(root == NULL) 
        return;
    
    cout << root->data;
    BTree_pre_order(root->leftChild);
    BTree_pre_order(root->rightChild);
}
void BTree_post_order(BiTreeNode* root){
    if(root == NULL) 
        return;
    BTree_post_order(root->leftChild);
    BTree_post_order(root->rightChild);
    cout << root->data;
}
void BTree_in_order(BiTreeNode* root){
    if(root == NULL) 
        return;
    
    BTree_in_order(root->leftChild);
    cout << root->data;
    BTree_in_order(root->rightChild);
}

int BTree_Leaves_Pre(BiTreeNode* root){
    if(root == NULL)
        return 0;
    int count = 0;
    if(root->leftChild == NULL && root->rightChild == NULL) // 中
        count = 1;
    count += BTree_Leaves_Pre(root->leftChild); // 左
    count += BTree_Leaves_Pre(root->rightChild); // 右
    return count;
}
void id181(){
    int t;
    cin >> t;
    while(t--){
        BiTreeNode* tree = new BiTreeNode;
        tree = BTree_Create();
        vector<FatherChild> relations;
        BTree_PC_pre(tree,'\0',relations);
        for(auto &relation: relations){
            cout << relation.child << " ";
        }
        cout << endl;
        for(auto &relation: relations){
            cout << relation.father << " ";
        }
        cout << endl;
    }
}
// void id378(){
//     int t;
//     cin >> t;
//     while(t--){
//         BiTreeNode* tree = new BiTreeNode;
//         tree = BTree_Create();
//         BTree_in_order(tree);
//         cout << endl;
//         BTree_post_order(tree);
//         cout << endl;
//     }
// }
// void id183(){
//     int t;
//     cin >> t;
//     while(t--){
//         BiTreeNode* tree = new BiTreeNode;
//         tree = BTree_Create();
//         int result = BTree_Leaves_Pre(tree);
//         cout << result << endl;
//     }
// }

void BTree_PC_pre(BiTreeNode *root, char parent, vector<FatherChild> &relations) {
    if (root == NULL)
        return;

    if (root->leftChild == NULL && root->rightChild == NULL) {
        // 当前节点是叶子节点，记录父节点和叶子节点的关系
        FatherChild relation = {parent, root->data};
        relations.push_back(relation);
    }

    BTree_PC_pre(root->leftChild, root->data, relations);
    BTree_PC_pre(root->rightChild, root->data, relations);
}


