#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 100

class BiTree;
class BiNode;

class BiNode {
    friend class BiTree;

private:
    char name;
    char fatherName;
    BiNode* lchild;
    BiNode* rchild;

public:
    BiNode() : name('0'), fatherName('0'), lchild(nullptr), rchild(nullptr) {}
    BiNode(char n, char f) : name(n), fatherName(f), lchild(nullptr), rchild(nullptr) {}
};

class BiTree {
private:
    BiNode* root;
    char y[MAX_SIZE];
    char father[MAX_SIZE];
    int x[MAX_SIZE];
    int cnt;

    BiNode* initBiNode() {
        return new BiNode();
    }

    void createBiTree(BiNode*& T, char name) {
        char ch;
        cin >> ch;
        if (ch == '#') {
            T = nullptr;
        } else {
            T = new BiNode(ch, name);
            createBiTree(T->lchild, T->name);
            createBiTree(T->rchild, T->name);
        }
    }

    void levelOrder() {
        queue<BiNode*> Q;
        if (root) Q.push(root);

        int i = 0, j = 0;
        while (!Q.empty()) {
            BiNode* S = Q.front();
            Q.pop();
            if (S) {
                y[i++] = S->name;
                father[j++] = S->fatherName;
                cnt++;
                if (S->lchild != nullptr) Q.push(S->lchild);
                if (S->rchild != nullptr) Q.push(S->rchild);
            }
        }
    }

    void getX() {
        x[0] = -1;
        for (int i = 1; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                if (father[i] == y[j]) x[i] = j;
            }
        }
    }

public:
    BiTree() : root(nullptr), cnt(0) {
        fill(x, x + MAX_SIZE, -1);
        fill(y, y + MAX_SIZE, '0');
        fill(father, father + MAX_SIZE, '0');
    }

    void initializeTree() {
        createBiTree(root, '-1');
    }

    void traverseAndPrint() {
        levelOrder();
        getX();
        for (int i = 0; i < cnt; i++) {
            cout << y[i];
            if (i == cnt - 1) cout << endl;
            else cout << " ";
        }
        for (int i = 0; i < cnt; i++) {
            cout << x[i];
            if (i == cnt - 1) cout << endl;
            else cout << " ";
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        BiTree tree;
        tree.initializeTree();
        tree.traverseAndPrint();
    }
    return 0;
}
