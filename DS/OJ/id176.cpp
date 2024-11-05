#include <iostream>
#include <cstring>
using namespace std;
 
class Node
{
public:
	int left, right;
	int weight;
	int parent;
};
 
class HufTree
{
public:
	Node* huftree;
	int max = 10000;
	int len;
	int lnum;
	string *code;
	void Init();
	void Init(int n, int* wei);
	void SelectMin(int pos, int* s0, int* s1);
	void Coding();
};
void HufTree::Init()
{
	for (int i = lnum + 1;i <= len;i++)
	{
		int s0, s1;
		SelectMin(i - 1, &s0, &s1);
		huftree[s0].parent = huftree[s1].parent = i;
		huftree[i].left = s0;
		huftree[i].right = s1;
		huftree[i].weight = huftree[s0].weight + huftree[s1].weight;
	}
}
void HufTree::Init(int n, int* wei)
{
	int i;
	lnum = n;
	len = 2 * n - 1;
	huftree = new Node[2 * n];
	code = new string[lnum + 1];
 
	for (i = 1;i <= n;i++)
	{
		huftree[i].weight = wei[i - 1];
	}
	for (i = 1;i <= len;i++)
	{
		if (i > n)
		{
			huftree[i].weight = 0;
		}
		huftree[i].parent = 0;
		huftree[i].left = 0;
		huftree[i].right = 0;
	}
	Init();
}
void HufTree::SelectMin(int pos, int* s0, int* s1)
{
	int w0, w1, i;
	w0 = w1 = max;
	*s0 = *s1 = 0;
	for (i=1;i <= pos;i++)
	{
		if (w0 > huftree[i].weight && !huftree[i].parent)
		{
			w1 = w0;
			*s1 = *s0;
			w0 = huftree[i].weight;
			*s0 = i;
		}
		else if (w1 > huftree[i].weight && !huftree[i].parent)
		{
			w1 = huftree[i].weight;
			*s1 = i;
		}
	}
}
void HufTree::Coding()
{
	char* tmp;
	int i, c, f, start;
	tmp = new char[lnum];
	tmp[lnum - 1] = '\0';
	for (i = 1;i <= lnum;i++)
	{
		start = lnum - 1;
		for (c = i, f = huftree[i].parent;f != 0;c = f, f = huftree[f].parent)
		{
			if (huftree[f].left == c)
			{
				tmp[--start] = '0';
			}
			else
			{
				tmp[--start] = '1';
			}
			code[i].assign(&tmp[start]);
		}
	}
	delete[]tmp;
}
int main()
{
	int t;
	t = 1;
	while (t--)
	{
		int n;
		cin >> n;
		int* weight = new int[n];
		for (int i = 0;i < n;i++)
		{
			cin >> weight[i];
		}
		HufTree tree;
		tree.Init(n, weight);
		tree.Coding();
		for (int i = 1;i <= n;i++)
		{
			cout << tree.huftree[i].weight << "-";
			cout << tree.code[i] << endl;
		}
		delete[]weight;
	}
}