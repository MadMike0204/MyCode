#include <iostream>
using namespace std;
int main(){

    int t,m,n;
    cin >> t;
    while(t > 0)
    {   
        cin >> m >> n;
        int** rect = new int*[m];
        for(int i=0;i<m;i++)
        {
            rect[i] = new int[n];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> rect[i][j];
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=m-1;i>=0;i--)
            {
                printf(i==0?"%d":"%d ",rect[i][j]);
            }
            cout << endl;
        }
        cout << endl;

        t--;
    }

    return 0;
}