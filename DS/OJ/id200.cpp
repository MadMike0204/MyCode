#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for max
using namespace std;

class BinaryTree {
private:
    struct Node {
        char data;
        int l, r; // 左右子树的索引
        Node() : data(' '), l(0), r(0) {}
    };
    vector<Node> tree; // 树的节点列表
    int idx;           // 当前节点的索引

    int build(const string& pre, const string& in, int n) {
        if (n == 0) return 0;

        int cur = ++idx;
        tree[cur].data = pre[0];

        int pos = in.find(pre[0]);
        tree[cur].l = build(pre.substr(1, pos), in, pos);
        tree[cur].r = build(pre.substr(pos + 1), in.substr(pos + 1), n - pos - 1);
        return cur;
    }

public:
    BinaryTree(int n, const string& pre, const string& in) : idx(0) {
        tree.resize(n + 1); // 初始化树节点，索引从1开始
        build(pre, in, n);
    }

    int getHeight(int u) const {
        if (u == 0) return 0;
        return max(getHeight(tree[u].l), getHeight(tree[u].r)) + 1;
    }
};

int main() {
    int n;
    string pre, in;
    cin >> n;
    cin.ignore(); // 忽略换行符，准备读下一行
    getline(cin, pre);
    getline(cin, in);

    BinaryTree tr(n, pre, in);
    cout << tr.getHeight(1) << endl; // 根节点默认从1开始

    return 0;
}