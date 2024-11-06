#include <iostream>
using namespace std;

class BitNode {
public:
    char data;                         // 数据域
    int tag;                           // 标记
    BitNode* leftChild;               // 左孩子
    BitNode* rightChild;              // 右孩子

    BitNode() : data(0), tag(0), leftChild(nullptr), rightChild(nullptr) {}
    BitNode(char ch) : data(ch), tag(0), leftChild(nullptr), rightChild(nullptr) {}
    
    ~BitNode() {
        delete leftChild;    // 递归删除左子树
        delete rightChild;   // 递归删除右子树
    }
};

class BitTree {
private:
    BitNode* root;                 // 根节点
    int len;                       // 树的长度

    BitNode* CreateBitTree() {
        char ch;
        cin >> ch;
        if (ch == '#') {
            return nullptr; // 节点为空
        } else {
            BitNode* node = new BitNode(ch);
            node->leftChild = CreateBitTree();   // 创建左子树
            node->rightChild = CreateBitTree();  // 创建右子树
            return node;
        }
    }

    void Traverse(BitNode* node) {
        if (node) {
            Traverse(node->leftChild);   // 先序遍历左子树
            Traverse(node->rightChild);  // 先序遍历右子树
            
            // 交换左右孩子
            BitNode* temp = node->rightChild;
            node->rightChild = node->leftChild;
            node->leftChild = temp;
        }
    }

    void FirstOrder(BitNode* node) {
        if (node) {
            cout << node->data << " "; // 访问节点
            FirstOrder(node->leftChild); // 访问左子树
            FirstOrder(node->rightChild); // 访问右子树
        }
    }

    void MidOrder(BitNode* node) {
        if (node) {
            MidOrder(node->leftChild); // 访问左子树
            cout << node->data << " "; // 访问节点
            MidOrder(node->rightChild); // 访问右子树
        }
    }

    void LastOrder(BitNode* node) {
        if (node) {
            LastOrder(node->leftChild); // 访问左子树
            LastOrder(node->rightChild); // 访问右子树
            cout << node->data << " "; // 访问节点
        }
    }

    void LevelOrder() {
        if (root == nullptr) {
            cout << "NULL" << endl;
            return;
        }
        
        BitNode* queue[1000]; // 队列实现
        int front = 0, rear = 0;
        queue[rear++] = root;

        while (front < rear) {
            BitNode* current = queue[front++];
            cout << current->data << " "; // 访问节点

            if (current->leftChild) {
                queue[rear++] = current->leftChild; // 加入左孩子
            }
            if (current->rightChild) {
                queue[rear++] = current->rightChild; // 加入右孩子
            }
        }
        cout << endl; // 结束行输出
    }

public:
    BitTree() : root(nullptr), len(0) {}

    void CreateTree() {
        root = CreateBitTree(); // 创建树
    }

    void Traverse() {
        Traverse(root); // 先序遍历并交换孩子
    }

    void FirstOrder() {
        if (root == nullptr) {
            cout << "NULL";
        } else {
            FirstOrder(root); // 先序遍历
        }
        cout << endl;
    }

    void MidOrder() {
        if (root == nullptr) {
            cout << "NULL";
        } else {
            MidOrder(root); // 中序遍历
        }
        cout << endl;
    }

    void LastOrder() {
        if (root == nullptr) {
            cout << "NULL";
        } else {
            LastOrder(root); // 后序遍历
        }
        cout << endl;
    }

    void LevelOrderTraversal() {
        LevelOrder(); // 层序遍历
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        BitTree tree;
        tree.CreateTree();
        tree.Traverse();
        tree.FirstOrder();
        tree.MidOrder();
        tree.LastOrder();
        tree.LevelOrderTraversal();
    }
    return 0;
}
