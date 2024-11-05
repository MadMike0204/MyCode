#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_WEIGHT = 9999999; // 假设结点权值不超过9999999

// 定义 Huffman 树节点类
class HuffNode {
public:
    int weight;       // 权值
    int parent;       // 父结点下标
    int leftChild;    // 左孩子下标
    int rightChild;   // 右孩子下标
    char character;    // 节点表示的字符

    HuffNode() : weight(0), parent(0), leftChild(0), rightChild(0), character(' ') {}
};

// 定义 Huffman 树类
class HuffmanTree {
private:
    vector<HuffNode> huffTree;   // 赫夫曼树，用数组表示
    vector<string> huffCode;      // 每个字符对应的赫夫曼编码
    int length;                   // 结点数量
    int leafCount;                // 叶子数量

    void makeTree();                           // 建树，私有函数，被公有函数调用
    void selectMin(int pos, int &s1, int &s2); // 找出权值最小的两个结点

public:
    HuffmanTree(int n, const vector<int>& weights, const vector<char>& characters); // 构造函数
    void coding();                            // 赫夫曼编码
    void destroy();                           // 销毁赫夫曼树
    int decode(const string& codeStr, string &textStr); // 解码
};

// 构造函数
HuffmanTree::HuffmanTree(int n, const vector<int>& weights, const vector<char>& characters) {
    leafCount = n;
    length = 2 * n - 1;
    huffTree.resize(length + 1);
    huffCode.resize(leafCount + 1);

    for (int i = 1; i <= n; i++) {
        huffTree[i].weight = weights[i - 1];
        huffTree[i].character = characters[i - 1];
    }
    
    for (int i = n + 1; i <= length; i++) {
        huffTree[i].weight = 0;
        huffTree[i].character = '0';
    }

    makeTree(); // 调用私有函数建树
}

void HuffmanTree::makeTree() {
    for (int i = leafCount + 1; i <= length; i++) {
        int s1, s2;
        selectMin(i - 1, s1, s2); // 找出两个最小权值的下标
        huffTree[s1].parent = i;
        huffTree[s2].parent = i;
        huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
        huffTree[i].leftChild = s1;
        huffTree[i].rightChild = s2;
    }
}

void HuffmanTree::selectMin(int pos, int &s1, int &s2) {
    int min1 = MAX_WEIGHT, min2 = MAX_WEIGHT;
    s1 = s2 = 0;

    for (int i = 1; i <= pos; i++) {
        if (huffTree[i].parent == 0) {
            if (huffTree[i].weight < min1) {
                min2 = min1;
                s2 = s1;
                min1 = huffTree[i].weight;
                s1 = i;
            } else if (huffTree[i].weight < min2) {
                min2 = huffTree[i].weight;
                s2 = i;
            }
        }
    }
}

// 赫夫曼编码
void HuffmanTree::coding() {
    vector<char> code(leafCount); // 用于生成编码的工作空间
    code[leafCount - 1] = '\0'; // 编码结束符

    for (int i = 1; i <= leafCount; ++i) {
        int start = leafCount - 1; // 编码结束符位置
        for (int c = i, f = huffTree[i].parent; f != 0; c = f, f = huffTree[f].parent) {
            code[--start] = (huffTree[f].leftChild == c) ? '0' : '1';
        }
        huffCode[i] = string(&code[start]); // 将编码保存到huffCode中
    }
}

void HuffmanTree::destroy() {
    huffTree.clear();
    huffCode.clear();
}

// 解码函数
int HuffmanTree::decode(const string& codeStr, string &textStr) {
    int current = length;
    textStr.clear();

    for (char ch : codeStr) {
        if (ch == '0') {
            current = huffTree[current].leftChild;
        } else if (ch == '1') {
            current = huffTree[current].rightChild;
        } else {
            return -1; // error
        }

        if (huffTree[current].leftChild == 0 && huffTree[current].rightChild == 0) {
            textStr += huffTree[current].character; // Append decoded character
            current = length; // Reset to root
        }
    }

    // Check if we ended on a valid character
    if (textStr.empty() || current != length) {
        return -1; // If we did not return to root or the text is empty, it's an error
    }

    return 1; // success
}

// 主函数
int main() {
    int testCaseCount = 1; // Assume a single test case
    int n;
    while (testCaseCount--) {
        cin >> n;
        vector<int> weights(n);
        vector<char> characters(n);

        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> characters[i];
        }

        HuffmanTree myHuff(n, weights, characters);
        myHuff.coding();

        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string codestr;
            cin >> codestr;
            string decodedStr;
            if (myHuff.decode(codestr, decodedStr) == 1) {
                cout << decodedStr << endl;
            } else {
                cout << "error" << endl;
            }
        }
        myHuff.destroy();
    }

    return 0;
}
