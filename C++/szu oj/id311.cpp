#include <iostream>
using namespace std;

class Rect
{
    friend Rect operator + (Rect&,Rect&);
    private:
        int row;
        int column;
        int** data;
    public:
        
        Rect(int r,int c,bool istemp)
        {
            row = r;
            column = c;
            data = new int*[r];
            for(int i=0;i<r;i++)
            {
                data[i] = new int[c];
            }
            if(!istemp)
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        cin >> data[i][j];
                    }
                }
            else
            {
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        data[i][j] = 0;
                    }
                }
            }
        }
        int getRow()
        {
            return row;
        }
        int getColumn()
        {
            return column;
        }
        void print()
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    printf(j==0?"%d":" %d",data[i][j]);
                }
                cout << endl;
            }
        }
};

Rect operator + (Rect&a,Rect&b)
{
    for(int i=0;i<a.getRow();i++)
    {
        for(int j=0;j<a.getColumn();j++)
        {
            a.data[i][j] += b.data[i][j];
        }
    }
    return a;
}

int main(){

    int t,row,column;
    cin >> t;
    while(t > 0)
    {
        cin >> row >> column;
        Rect r1(row,column,0);
        Rect r2(row,column,0);
        r1 = r1 + r2;
        r1.print();
        t--;
    }

    return 0;
}