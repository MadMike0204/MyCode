#include <iostream>
#include <cstring>
using namespace std;

class Pattern
{
    private:
        bool** data;
        int size;
    public:
        Pattern(int n)
        {
            size = n;
            data = new bool*[n];
            for(int i=0;i<n;i++)
            {
                data[i] = new bool[n];
                for(int j=0;j<size;j++)
                {
                    data[i][j] = 0;
                }
            }
        }
        Pattern(const Pattern& B)
        {
            this->size = B.size;
            data = new bool*[size];
            for(int i=0;i<size;i++)
            {
                data[i] = new bool[size];
            }
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    data[i][j] = B.data[i][j];
                }
            }
        }
        Pattern& operator=(const Pattern& B)
        {
            this->size = B.size;
            data = new bool*[size];
            for(int i=0;i<size;i++)
            {
                data[i] = new bool[size];
            }
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    data[i][j] = B.data[i][j];
                }
            }
            return *this;
        }
        void Input()
        {
            char ch;
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    cin >> ch;
                    if(ch == '@')
                        data[i][j] = 0;
                    else if(ch == '-')
                        data[i][j] = 1;
                }
            }
        }
        void Print()
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    if(data[i][j] == 0)
                        cout << '@';
                    else
                        cout << '-';
                }
                cout << endl;
            }
        }
        void Combine90()
        {   
            Reflect();
            RotateCW90();
        }
        void Combine180()
        {
            Reflect();
            RotateCW180();
        }
        void Combine270()
        {
            Reflect();
            RotateCW270();
        }
        void RemainTheSame()
        {
            return;
        }
        void Reflect()
        {
            if(data == NULL)
                return;
            bool temp = 0;
            for(int i=0;i<size/2;i++)
            {
                for(int j=0;j<size;j++)
                {
                    temp = data[j][i];
                    data[j][i] = data[j][size-i-1];
                    data[j][size-i-1] = temp;
                }
            }   
        }
        void RotateCW90()
        {
            if(data == NULL)
                return;
            bool** temp = new bool*[size];
            for(int i=0;i<size;i++)
            {
                temp[i] = new bool[size];
            }
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    temp[j][size-i-1] = data[i][j];
                }
            }
            for(int i=0;i<size;i++)
            {
                delete[] data[i];
            }
            delete[] data;
            data = temp;
        }
        void RotateCW180()
        {
            RotateCW90();
            RotateCW90();
        }
        void RotateCW270()
        {
            RotateCW90();
            RotateCW90();
            RotateCW90();
        }
        bool Compare(Pattern &A,Pattern &B)
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    if(A.data[i][j] != B.data[i][j])
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }
        ~Pattern()
        {
            if(data != NULL)
            {
                for(int i=0;i<size;i++)
                {
                    delete[] data[i];
                }
            }
            delete[] data;
        }
};
void test()
{
    Pattern A(3);
    A.Input();
    A.RotateCW90();
    A.Print();
    cout << endl;
    A.RotateCW90();
    A.Print();
    cout << endl;
    A.RotateCW90();
    A.Print();
    cout << endl;
}

int main(){

    int size;
    cin >> size;
    Pattern A(size);
    A.Input();
    Pattern B(size);
    B.Input();
    Pattern C = A;
    
    int flag = -1;
    //90
    C.RotateCW90();
    if(C.Compare(B,C) && flag <0)
    {
        flag = 1;
    }
    C = A;
    //180
    C.RotateCW180();
    if(C.Compare(B,C) && flag <0)
    {
        flag = 2;
    }
    C = A;
    //270
    C.RotateCW270();
    if(C.Compare(B,C) && flag <0)
    {
        flag = 3;
    }
    C = A;
    //Reflect
    C.Reflect();
    if(C.Compare(B,C) && flag <0)
    {
        flag = 4;
    }
    C = A;
    //Combine
    C.Combine90();
    if(C.Compare(B,C) && flag <0)
    {
        flag = 5;
    }
    C = A;
    C.Combine180();
    if(C.Compare(B,C) && flag <0)
    {
        flag = 5;
    }
    C = A;
    C.Combine270();
    if(C.Compare(B,C) && flag <0)
    {
        flag = 5;
    }
    C = A;
    C.RemainTheSame();
    if(C.Compare(B,C) && flag <0)
    {
        flag = 6;
    }
    if(flag < 0)
        flag = 7;

    cout << flag << endl;

    return 0;
}