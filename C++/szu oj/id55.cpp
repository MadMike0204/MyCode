#include <iostream>
using namespace std;
int main(){

    int m,n,sum=0;
    cin >> m >> n;
    int rect[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> rect[i][j];
            sum += rect[i][j];
        }
    }
    printf("%d\n",sum);
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            cout << rect[i][j] << " ";
        }
        if(j != (n-1))cout << endl;
    }

    return 0;
}