#include <iostream>
using namespace std;

class MineField
{
    private:
        int column;
        int row;
        char** map;
        char** signed_map;
        int Scan(char** map,int aim_row,int aim_column)
        {
            int sum = 0;
            for(int i=aim_row-1;i<row && i<=aim_row+1;i++)
            {
                for(int j=aim_column-1;j<column && j<=aim_column+1;j++)
                {
                    if(i < 0 || j < 0)
                        continue;
                    if(map[i][j] == '*')
                        sum++;
                }
            }
            return sum;
        }
        void SignTheMap()
        {
            int i,j;

            signed_map = new char*[row];
            for(i=0;i<row;i++)
            {
                signed_map[i] = new char[column];
            }

            for(i=0;i<row;i++)
            {
                for(j=0;j<column;j++)
                {
                    if(map[i][j] == '*')
                    {
                        signed_map[i][j] = '*';
                    }
                    else if(map[i][j] == '?')
                    {
                        signed_map[i][j] = Scan(map,i,j) + 48;
                    }
                }
            }
        }
    public:
        MineField(int m,int n):column(n),row(m)
        {
            string temp;
            int i,j;

            map = new char*[m];
            for(i=0;i<m;i++)
            {
                map[i] = new char[n];
            }

            for(i=0;i<m;i++)
            {
                getline(cin,temp);
                for(j=0;j<n;j++)
                {
                    map[i][j] = temp[j];
                }
            }
        }
        ~MineField()
        {
            if(map != NULL && signed_map != NULL)
            {
                for(int i=0;i<row;i++)
                {
                    delete[] map[i];
                    delete[] signed_map[i];
                }
                delete[] map;
                delete[] signed_map;
            }
        }
        void DisplayOrigin();
        void DisplaySigned();
};

int main(){

    int m,n;
    cin >> m >> n;
    cin.ignore();

    MineField jojo(m,n);
    jojo.DisplaySigned();

    return 0;
}

void MineField::DisplayOrigin()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}
void MineField::DisplaySigned()
{
    SignTheMap();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout << signed_map[i][j];
        }
        cout << endl;
    }
}