#include <iostream>
#include<string>
using namespace std;

class Student {
private:
	// 静态数据成员，记录学生数量

/********** Write your code here! **********/


static int count;

/*******************************************/
public:
	//构造函数增加学生数量

	//析构函数减少学生数量

    // 静态函数成员，返回学生数量

/********** Write your code here! **********/

	//构造函数增加学生数量
    Student() {
        count++;
    }

	//析构函数减少学生数量
    ~Student() {
        count--;
    }

    // 静态函数成员，返回学生数量
    static int getCount() {
        return count;
    }
};


/*******************************************/

// 类外初始化静态成员
/********** Write your code here! **********/
int Student::count = 0;



/*******************************************/
int main() {
	int n,c;
	cin >> n;
	Student* students[n];  // 用于管理动态创建的对象

	for (int i = 0; i < n; ++i) {
		string op;
		cin >> op;
		if (op == "enter") {
			c = Student::getCount();
			students[c] = new Student;  // 创建对象，count 增加
		}
		else if (op == "leave") {
			c = Student::getCount();
			delete students[c - 1];  // 销毁对象，count 减少
		}
	}

	cout << Student::getCount() << endl;
	return 0;
}