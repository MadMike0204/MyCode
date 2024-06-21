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
RMB::RMB(int a,int b,int c):
    yuan(a),jiao(b),fen(c){}
bool RMB::operator > (RMB &r)
{
    if(yuan > r.yuan)
    {
        return 1;
    }
    else if(yuan < r.yuan)
    {
        return 0;
    }
    else
    {
        if(jiao > r.jiao)
        {
            return 1;
        }
        else if(jiao < r.jiao)
        {
            return 0;
        }
        else 
        {
            if(fen > r.fen)
            {
                return 1;
            }
            else if(fen < r.fen)
            {
                return 0;
            }
            else
            {
                return 0;
            }
        }
    }
}
ostream & operator <<(ostream &stream, RMB& r)
{
    cout << r.yuan << "yuan" << r.jiao << "jiao" << r.fen << "fen";
    return stream;
}
istream & operator >>(istream &stream, RMB& r)
{
    cin >> r.yuan >> r.jiao >> r.fen;
    return stream;
}
RMB operator +(RMB&a, RMB&b)
{
    RMB temp;
    temp.yuan = a.yuan + b.yuan;
    temp.jiao = a.jiao + b.jiao;
    temp.fen = a.fen + b.fen;
    if(temp.fen >= 10)
    {
        temp.jiao += (temp.fen/10);
        temp.fen %= 10;
    }
    if(temp.jiao >= 10)
    {
        temp.yuan += (temp.jiao/10);
        temp.jiao %= 10;
    }
    return temp;
}
/*******************************************/
//主函数
int main()
{	int t;
	double val_yuan; 
	cin>>t;
	while (t--)
	{	cin>>val_yuan;	//输入一个浮点数，例如1.23 
		RMB r1(val_yuan); //例如上一行输入1.23，则生成对象r1是1元2角3分 
		RMB r2;
		cin>>r2;	//输入一行三个整数参数，按元、角、分输入 

		if (r1>r2) 		cout<<r1<<" > "<<r2<<endl;
		else 			cout<<r1<<" <= "<<r2<<endl;
		RMB r3 = r1+r2;
		cout<<r1<<" + "<<r2<<" = "<<r3<<endl;
	}
	return 0;
}
