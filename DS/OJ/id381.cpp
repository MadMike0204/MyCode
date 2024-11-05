#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    char name;           // 节点的名字
    int father;          // 父节点的位置
    vector<int> children; // 孩子的列表

    TreeNode() : name('0'), father(-1) {}
};

class Tree {
private:
    int n; // 节点数量
    vector<TreeNode> nodes; // 节点列表

public:
    Tree(int size) : n(size) {
        nodes.resize(n);
    }

    void initializeTree() {
        for (int i = 0; i < n; i++) {
            cin >> nodes[i].name;
        }

        for (int i = 0; i < n; i++) {
            cin >> nodes[i].father;
            int fatherIndex = nodes[i].father;
            if (fatherIndex != -1) {
                nodes[fatherIndex].children.push_back(i);
            }
        }
    }

    void printTree() const {
        for (int i = 0; i < n; i++) {
            
            cout << nodes[i].name << " ";
            if (nodes[i].children.empty()) {
                cout << "-1" <<" ";
            } else {
                for (int child : nodes[i].children) {
                    cout << child << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Tree tree(n);
    tree.initializeTree();
    tree.printTree();
    cout << endl;
    return 0;
}
