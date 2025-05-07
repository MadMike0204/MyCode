#include <iostream>
using namespace std;
//完成Horse类和Pegasus类的定义，要求实现继承机制
/********** Write your code here! **********/





/*******************************************/
int main()
{
	int n;
	cin >> n;
	if (n == 0) {
		Horse *p1 = new Horse;   /*输出：
									Horse 申请了空间...
								*/
		p1->Fly(); //输出：Just a horse.
		delete p1; //输出：Horse 释放了空间...
	}
	else {
		Pegasus *p2 = new Pegasus; /*  输出两行：
										Horse 申请了空间...
										Pegasus 申请了空间...
									*/
		p2->Fly(); //输出：I can fly!
		delete p2; /* 输出两行：
				   Pegasus 释放了空间...
				   Horse 释放了空间...
				   */
	}
	return 0;
}