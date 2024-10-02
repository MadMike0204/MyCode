#include <iostream>
#include<cstring>
#include <queue>
using namespace std;
int find(int x[][100], int n)   //函数作用(找到数据在表中的第几组)
{	for (int i = 0; i <= 100; i++){ 
		for (int j = 0; j < 100; j++){
			if (x[i][j] == n){
				return i;
			}
		}
	}
	return -1;
}
void enqueue(queue<int>*& a, queue<int>& b, int n, int nn, int* ON)//记得加 & 进行引用,
{
	a[n].push(nn);
	if (ON[n] == 0){
		b.push(n);
		ON[n] = 1;
	}
}
void dequeue(queue<int>*& a, queue<int>& b, int* ON)
{
	if (!b.empty()){
		int n = b.front();
		if (!a[n].empty())
		{
			cout << a[n].front();
			a[n].pop();
		}
		if (a[n].empty()){
			b.pop();
			ON[n] = 0;
		}
	}
}
int main()
{
	int t,flag = 0;
	cin >> t;
	queue<int>* a = new queue<int>[t];
	queue<int> b;
	int ON[100];
	for (int i = 0; i < 100; i++){
		ON[i] = 0;
	}
	int x[100][100]{};
	for (int i = 0; i < t; i++)  //  录入分组的表
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++){
			cin >> x[i][j];
		}
	}
	while (1)
	{
		string str;
		cin >> str;
		int name = 0;
		if (str == "ENQUEUE"){
			cin >> name;
			int n = find(x, name);
			enqueue(a, b, n, name, ON);
		}
		else if (str == "DEQUEUE"){
			if (flag == 0){
				flag = 1;
			}
			else{
				cout << " ";
			}
			int n = find(x, name);
			dequeue(a, b, ON);
		}
		else if (str == "STOP"){
			break;
		}
	}
	return 0;
}