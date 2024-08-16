#include <iostream>
#include <cstring>
using namespace std;

class MagicSquare
{
    private:
        int** square;
        int size;
    public:
        MagicSquare(int size)
        {
            square = new int*[size];
            for(int i=0;i<size;i++)
            {
                square[i] = new int[size];
            }
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    square[i][j] = 0;
                }
            }
            this->size = size;
        }
        void Fill()
        {
            square[0][size/2] = 1;
            int location_column = size/2;
            int location_row = 0;
            int row,column;
            for(int i=2;i<=size*size;i++)
            {
                if(location_row == 0 && location_column < size-1)
                {
                    row = size-1;
                    column = location_column+1;
                }
                else if(location_row > 0 && location_column == size-1)
                {
                    column = 0;
                    row = location_row-1;
                }
                else if(location_row == 0 && location_column == size-1)
                {
                    row = location_row+1;
                    column = location_column;
                }
                else if(location_row > 0 && location_column < size-1)
                {
                    if(square[location_row-1][location_column+1] == 0)
                    {
                        row = location_row-1;
                        column = location_column+1;
                    }
                    else
                    {
                        row = location_row+1;
                        column = location_column;
                    }     
                }
                square[row][column] = i;  
                location_column = column;
                location_row = row;
            }
        }
        void Print()
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    printf(j==0?"%d":" %d",square[i][j]);
                }
                cout << endl;
            }
        }
        ~MagicSquare()
        {
            if(square != NULL)
            for(int i=0;i<size;i++)
            {
                if(square[i] != NULL)
                    delete[] square[i];
            }
            delete[] square;
        }
};

int main(){

    int N;
    cin >> N;
    MagicSquare JOJO(N);
    JOJO.Fill();
    JOJO.Print();

    return 0;
}