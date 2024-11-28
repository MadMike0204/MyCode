#include <iostream>
using namespace std;
int main(){

    int m,n,t;
    cin >> t;
    while(t>0)
    {
        cin >> m >> n;
        int rect[m][n];
        int* p = &rect[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> rect[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=m-1;j>=0;j--)
            {
                cout << rect[j][i] << " ";
            }
            cout << endl;
        }
        t--;
    }

    return 0;
}
