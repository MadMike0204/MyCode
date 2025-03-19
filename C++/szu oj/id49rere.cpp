#include <iostream>
#include <algorithm>
#include <iomanip>
#include<string>

using namespace std;

string number_rule[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
string flower[6] = { "大王","小王","黑桃","红桃","梅花","方块" };

//扑克牌结构体
struct Poke {
	string name;
	int number;
	int flower;
};

//判断A中的数字对应数字数组number_rule的下标是多少
int judge_number(string A) {
	for (int i = 0; i < 13; i++) {
		//表示A中含有里面的字串
		if(A.find(number_rule[i]) != string::npos)
			return i;
	}
	return -1;
}

//判断A中的花色对应花色数组flower的下标是多少
int judge_flower(string A) {
	for (int i = 0; i < 6; i++) {
		if (A.find(flower[i]) != string::npos)
			return i;
	}
	return -1;
}

//两张扑克牌的排序比较规则，用于sort函数
bool cmp(Poke A, Poke B) {
	if (A.flower != B.flower)
		return A.flower < B.flower;
	else
		return A.number > B.number;
}

int main()
{
	int t;
	cin >> t;								      //测试案例个数
	while (t--) {
		int n;
		cin >> n;								  //该组案例的扑克牌张数
		Poke *A = new Poke[n];
		for (int i = 0; i < n; i++) {
			cin >> A[i].name;					  //输入该张牌的名字
			A[i].number = judge_number(A[i].name);//得到该牌的数字对应的下标
			A[i].flower = judge_flower(A[i].name);//得到该牌的花色对应的下标
		}
		sort(A, A + n, cmp);					  //从大到小进行排序
		for (int i = 0; i < n; i++) {			  //进行该组测试的输出
			if (i != n - 1)
				cout << A[i].name << " ";
			else
				cout << A[i].name << endl;
		}
	}
	return 0;
}
