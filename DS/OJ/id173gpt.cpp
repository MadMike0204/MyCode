#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HTNode {
private:
    char data;            // 节点数据
    int weight;           // 节点权重
    HTNode* lchild;       // 左孩子
    HTNode* rchild;       // 右孩子

public:
    HTNode() : weight(0), lchild(nullptr), rchild(nullptr) {}

    char getData() const { return data; }
    int getWeight() const { return weight; }
    HTNode* getLeftChild() { return lchild; }
    HTNode* getRightChild() { return rchild; }

    void setData(char d) { data = d; }
    void setWeight(int w) { weight = w; }
    void createChildren() {
        lchild = new HTNode(); // 动态分配左孩子
        rchild = new HTNode(); // 动态分配右孩子
    }

    ~HTNode() { // 析构函数释放内存
        delete lchild;
        delete rchild;
    }
};

class HuffmanTree {
private:
    HTNode* root;          // 树根
    int leafCount;         // 叶子节点数量
    string treeStructure;  // 树的结构字符串
    vector<int> weights;   // 权重数组

    void createTree(HTNode* p, int& i, int& j);
    void preOrderTraversal(HTNode* p, int level, int& totalWeight);

public:
    HuffmanTree();
    ~HuffmanTree(); // 添加析构函数
    void createTree();
    void preOrder();
};

HuffmanTree::HuffmanTree() {
    cin >> treeStructure;
    cin >> leafCount;
    weights.resize(leafCount); // 使用vector管理权重数组
    for (int i = 0; i < leafCount; i++) {
        cin >> weights[i];
    }
    root = new HTNode(); // 初始化根节点
}

HuffmanTree::~HuffmanTree() { // 析构函数
    delete root; // 删除根节点，递归删除所有子节点
}

void HuffmanTree::createTree(HTNode* p, int& i, int& j) {
    if (treeStructure[i] != '0') {
        p->setData(treeStructure[i]);
        if (isupper(treeStructure[i])) {
            p->setWeight(weights[j]);
            j++;
        }
        i++;
        p->createChildren(); // 创建左、右孩子
        createTree(p->getLeftChild(), i, j);
        i++;
        createTree(p->getRightChild(), i, j);
    }
}

void HuffmanTree::createTree() {
    int i = 0, j = 0;
    createTree(root, i, j);
}

void HuffmanTree::preOrder() {
    int level = 0, totalWeight = 0;
    preOrderTraversal(root, level, totalWeight);
    cout << totalWeight << endl;
}

void HuffmanTree::preOrderTraversal(HTNode* p, int level, int& totalWeight) {
    if (p) {
        if (p->getWeight() > 0) { // 仅在叶子节点计算权重
            totalWeight += p->getWeight() * level;
        }
        level++;
        preOrderTraversal(p->getLeftChild(), level, totalWeight);
        preOrderTraversal(p->getRightChild(), level, totalWeight);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        HuffmanTree myTree;
        myTree.createTree();
        myTree.preOrder();
    }
    return 0;
}