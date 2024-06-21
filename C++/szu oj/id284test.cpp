#include <iostream>
using namespace std;

class RMB;
ostream & operator <<(ostream &, RMB &);
istream & operator >>(istream &, RMB &);

class RMB{
protected:
	int yuan, jiao, fen;
public:
	RMB(double a=0.0);
	RMB (int, int, int); 
	bool operator > (RMB &);
	friend ostream & operator <<(ostream &, RMB&); //一行输出，无换行
	friend istream & operator >>(istream &, RMB&);
	friend RMB operator +(RMB&, RMB&);
	void print()
	{
		cout << yuan << "." << jiao << fen << endl;
	}
};
//完成以下类定义的填空
/********** Write your code here! **********/
RMB::RMB(double a)
{
    a += 0.002;
    yuan = (int)a;
    
    a -= yuan * 1;
	jiao = (int)(a * 10);

	a -= (jiao * 0.1);	
	fen = (int)(a * 100);
}

/*******************************************/
//主函数
int main()
{	
	RMB jojo(2.33);
	jojo.print();
}
