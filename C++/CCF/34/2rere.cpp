#include <iostream>
using namespace std;

class Matrix
{
    private:
        int* arr = NULL;
        int** data = NULL;
        int row;
        int column;
        int sum;
    private:
        void ReleaseData()
        {
            if(data != NULL)
            {
                for(int i=0;i<row;i++)
                {
                    delete[] data[i];
                }
                delete[] data;
            }
        }
        void ReleaseArr()
        {
            if(arr != NULL)
            {
                delete[] arr;
            }
        }
    public:
        Matrix(int r,int c):row(r),column(c)
        {   
            sum = row * column;
            data = new int*[row];
            for(int i=0;i<row;i++)
            {
                data[i] = new int[column];
            }
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    cin >> data[i][j];
                }
            }
            CreateArr();
        }
        void CreateArr()
        {
            arr = new int[sum];
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    arr[i*column+j] = data[i][j];
                }
            }
        }
        void Reform(int p,int q)
        {   
            ReleaseData();
            row = p;
            column = q;
            data = new int*[row];
            for(int i=0;i<row;i++)
            {
                data[i] = new int[column];
            }
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    data[i][j] = arr[column*i+j];
                }
            }
        }
        void Transpose()
        {
            int** temp = new int*[column];
            for(int i=0;i<column;i++)
            {
                temp[i] = new int[row];
            }
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    temp[j][i] = data[i][j];
                }
            }
            ReleaseData();
            ReleaseArr();
            int tp = column;
            column = row;
            row = tp;
            data = temp;
            CreateArr();
        }
        int Find(int i,int j)
        {
            return data[i][j];
        }
        ~Matrix()
        {
            ReleaseArr();
            ReleaseData();
        }
};

int main(){

    int n,m,t,op,a,b;
    cin >> n >> m >> t;
    Matrix JOJO(n,m);

    while(t--)
    {
        cin >> op >> a >> b;
        if(op == 1)
        {
            JOJO.Reform(a,b);
        }
        else if(op == 2)
        {
            JOJO.Transpose();
        }
        else if(op == 3)
        {
            cout << JOJO.Find(a,b) << endl;
        }
    }

    return 0;
}