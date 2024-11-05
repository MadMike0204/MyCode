#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define ok 1
#define error -1
const int MaxW = 9999999; // 假设结点权值不超过9999999
// 定义huffman树结点类
class HuffNode
{
public:
	int weight;		// 权值
	int parent;		// 父结点下标
	int leftchild;	// 左孩子下标
	int rightchild; // 右孩子下标
	char cha;
};
// 定义赫夫曼树类
class HuffMan
{
private:
	void MakeTree();						   // 建树，私有函数，被公有函数调用
	void SelectMin(int pos, int *s1, int *s2); // 从 1 到 pos 的位置找出权值最小的两个结点，把结点下标存在 s1 和 s2 中
public:
	int len;								   // 结点数量
	int lnum;								   // 叶子数量
	HuffNode *huffTree;						   // 赫夫曼树，用数组表示
	string *huffCode;						   // 每个字符对应的赫夫曼编码
	void MakeTree(int n, int wt[], char ct[]); // 公有函数，被主函数main调用
	void Coding();							   // 公有函数，被主函数main调用
	void Destroy();
	int Decode(const string codestr, char txtstr[]); //输入编码串condestr
	//输出解码串txtstr
};

// 构建huffman树
void HuffMan::MakeTree(int n, int wt[], char ct[])
{
	// 参数是叶子结点数量和叶子权值
	// 公有函数，对外接口
	int i;
	lnum = n;
	len = 2 * n - 1;
	huffTree = new HuffNode[2 * n];
	huffCode = new string[lnum + 1]; // 位置从 1 开始计算
	// huffCode实质是个二维字符数组，第 i 行表示第 i 个字符对应的编码
	// 赫夫曼树huffTree初始化
	for (i = 1; i <= n; i++)
	{
		huffTree[i].weight = wt[i - 1];
		huffTree[i].cha = ct[i - 1];
	}
	huffTree[i].weight = wt[i - 1]; // 第0号不用，从1开始编号
	for (i = 1; i <= len; i++)
	{
		if (i > n)
		{
			huffTree[i].weight = 0; // 前n个结点是叶子，已经设置
			huffTree[i].cha = '0';
		}
		huffTree[i].parent = 0;
		huffTree[i].leftchild = 0;
		huffTree[i].rightchild = 0;
	}
	MakeTree(); // 调用私有函数建树
}

void HuffMan::SelectMin(int pos, int *s1, int *s2)
{
	// 找出最小的两个权值的下标
	// 函数采用地址传递的方法，找出两个下标保存在 s1 和 s2 中
	int w1, w2, i;
	w1 = w2 = MaxW; // 初始化w1和w2为最大值，在比较中会被实际的权值替换
	*s1 = *s2 = 0;
	for (i = 1; i <= pos; i++)
	{
		if (huffTree[i].parent == 0 && huffTree[i].weight < w1)
		{
			w2 = w1;
			*s2 = *s1;
			w1 = huffTree[i].weight;
			*s1 = i;
		}
		else if (huffTree[i].weight < w2 && huffTree[i].parent == 0)
		{
			w2 = huffTree[i].weight;
			*s2 = i;
		}
	}
}

void HuffMan::MakeTree()
{
	// 私有函数，被公有函数调用
	int i, s1, s2;
	for (i = lnum + 1; i <= len; i++)
	{
		SelectMin(i - 1, &s1, &s2); // 找出两个最小权值的下标放入 s1 和 s2 中
		huffTree[s1].parent = i;
		huffTree[s2].parent = i;
		huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
		huffTree[i].leftchild = s1;
		huffTree[i].rightchild = s2;
	}
}

// 销毁赫夫曼树
void HuffMan::Destroy()
{
	len = 0;
	lnum = 0;
	delete[] huffTree;
	delete[] huffCode;
}

// 赫夫曼编码
void HuffMan::Coding()
{
	char *cd;
	int i, c, f, start;
	// 求 n 个结点的赫夫曼编码
	cd = new char[lnum]; // 分配求编码的工作空间
	cd[lnum - 1] = '\0'; // 编码结束符
	for (i = 1; i <= lnum; ++i)
	{
		// 逐个字符求赫夫曼编码
		start = lnum - 1; // 编码结束符位置
		// 参考课本P147算法6.12 HuffmanCoding代码
		for (c = i, f = huffTree[i].parent; f != 0; c = f, f = huffTree[f].parent)
		{
			if (huffTree[f].leftchild == c)
			{
				cd[--start] = '0';
			}
			else
			{
				cd[--start] = '1';
			}
		}
		huffCode[i] = new char[lnum - start];
		huffCode[i].assign(&cd[start]); // 把cd中从start到末尾的编码复制到huffCode中
	}
	delete[] cd; // 释放工作空间
}

int HuffMan::Decode(const string codestr, char txtstr[])
{
	int i, k, c;
	char ch;
	c = len;
	k = 0;
	for (i = 0; i < codestr.length(); i++)
	{
		ch = codestr[i];
		if (ch == '0')
		{
			c = huffTree[c].leftchild;
		}
		else if (ch == '1')
		{
			c = huffTree[c].rightchild;
		}
		else if (ch != '0' && ch != '1')
		{
			return error;
		}
		if (huffTree[c].leftchild == 0 && huffTree[c].rightchild == 0)
		{
			txtstr[k] = huffTree[c].cha;
			k++;
			c = len;
		}
		else
		{
			ch = '\0';
		}
	}
	if (ch == '\0')
		return error;
	else
		txtstr[k] = '\0';
	return ok;
}

// 主函数
int main()
{
	int t, n, i, j, k;
	int wt[800];
	char ct[800];
	HuffMan myHuff;
	t = 1;
	string codestr;
	char txtstr[800];
	for (i = 0; i < t; i++)
	{
		cin >> n;
		for (j = 0; j < n; j++)
		{
			cin >> wt[j];
		}
		for (j = 0; j < n; j++)
		{
			cin >> ct[j];
		}
		myHuff.MakeTree(n, wt, ct);
		myHuff.Coding();
		cin >> k;
		for (j = 0; j < k; j++)
		{
			cin >> codestr;
			if (myHuff.Decode(codestr, txtstr) == 1)
			{
				cout << txtstr << endl;
			}
			else
			{
				cout << "error" << endl;
			}
		}
		myHuff.Destroy();
	}
	return 0;
}
