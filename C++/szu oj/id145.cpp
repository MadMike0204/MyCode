#include <iostream>
using namespace std;

class Matrix
{
    private:
        int row;
        int column;
        int** matrix;
    public:
        Matrix(int row_in,int column_in)
        {
            row = row_in;
            column = column_in;
            matrix = new int*[row_in];
            for(int i=0;i<row_in;i++)
            {
                matrix[i] = new int[column_in];
            }
            for(int i=0;i<row_in;i++)
            {
                for(int j=0;j<column_in;j++)
                {
                    cin >> matrix[i][j];
                }
            }
        }
        Matrix(const Matrix &pp)
        {
            row = pp.column;
            column = pp.row;
            matrix = new int*[row];
            for(int i=0;i<row;i++)
            {
                matrix[i] = new int[column];
            }
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    matrix[i][j] =  pp.matrix[column-j-1][i];
                }
            }
        }
        void OutPutMatrix()
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    printf(j==0?"%d":" %d",matrix[i][j]);
                }
                cout << endl;
            } 
        }
        ~Matrix()
        {
            for(int i=0;i<row;i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
};

int main(){

    int t,m,n;
    cin >> t;
    while(t>0)
    {
        cin >> m >> n;
        Matrix newnew(m,n);
        Matrix cancanneed(newnew);

        cout << "before:" << endl;
        newnew.OutPutMatrix();
        cout << "after:" << endl;
        cancanneed.OutPutMatrix();

        t--;
        if(t != 0)
        {
            cout << endl;
        }
    }

    return 0;
}

/*【id:145】【25分】C. OOP矩阵的右旋（类拷贝构造与析构）
时间限制
1s
内存限制
128MB
题目描述

定义一个矩阵类，其中包含了矩阵的维数，矩阵，以及需要的方法 

为该矩阵类定义一个拷贝构造函数，复制另一个矩阵对象的矩阵。

对复制矩阵类对象的矩阵进行右旋操作。

比如现在有2*3矩阵 ：

1 2 3

4 5 6 

向右旋转90度后的矩阵变为：

4 1

5 2

6 3

要求：矩阵类内的矩阵需要使用new方法，动态生成，并且在调用结束后使用析构函数释放空间。


输入

 第一行输入t表示有t个测试实例

连续m行，输入矩阵维数m和n，然后输入一个m*n的矩阵的数据

依次输入t个实例


输出

 依次输出右转前后的矩阵

在输出的每行中，每个数据之间都用空格隔开*/