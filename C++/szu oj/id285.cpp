#include <iostream>
using namespace std;

class Point;
Point operator -- (Point & );
Point operator -- (Point &, int);

class Point {
private:
	int x, y, z;
public:
	Point(int tx=0, int ty=0, int tz=0 )
	{	x = tx, y = ty, z = tz;	}
	Point operator ++ ();
	Point operator ++ (int);
	friend Point operator -- (Point & );
	friend Point operator -- (Point &, int);
	void print();
};
//完成以下填空
/********** Write your code here! **********/
void Point::print()
{
    cout << "x=" << this->x
         << " y=" << this->y
         << " z=" << this->z << endl; 
}
Point Point::operator++ (int)
{
    Point temp = *this;
    this->x++;
    this->y++;
    this->z++;
    return temp;
}
Point Point::operator++ ()
{
    this->x++;
    this->y++;
    this->z++;
    return *this;
}
Point operator --(Point& p,int)
{
    Point temp = p;
    p.x--;
    p.y--;
    p.z--;
    return temp;
}
Point operator --(Point& p)
{
    p.x--;
    p.y--;
    p.z--;
    return p;
}


/*******************************************/
int main()
{	int tx, ty, tz;
	cin>>tx>>ty>>tz;
	Point p0(tx, ty, tz); //原值保存在p0
	Point p1, p2;	//临时赋值进行增量运算

	//第1行输出
	p1 = p0;
	p1++;;
	p1.print();
	//第2行输出
	p1 = p0;
	p2 = p1++;
	p2.print();
	//第3、4行输出，前置++
	p1 = p0;
	(++p1).print();
	p1.print();
	//第5、6行输出，后置--
	p1 = p0;
	p1--;
	p1.print();
	p0.print();
	//第7、8行输出，前置--
	p1 = p0;
	(--p1).print();
	p1.print();

	return 0;
}




/*
【id:285】【30分】A. 【程序填空】三维点坐标平移（增量运算符重载）
时间限制
1s
内存限制
128MB
题目描述

定义一个三维点Point类，利用友元函数重载"++"和"--"运算符，并区分这两种运算符的前置和后置运算。

++表示x\y\z坐标都+1，--表示x\y\z坐标都-1

请完成以下程序填空


输入

只有一行输入，输入三个整数，表示点的x/y/z坐标

 

 


输出

由主函数自行输出

 


IO模式

本题IO模式为标准输入/输出(Standard IO)，你需要从标准输入流中读入数据，并将答案输出至标准输出流中。


*/