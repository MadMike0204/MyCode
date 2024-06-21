#include<iostream>
using namespace std;
int main(){

    int m,n,t,min,max;
    cin >> t;
    while(t>0)
    {
        min = 999;
        max = -999;
        cin >> m >> n;
        int** p = new int*[n];
        for(int i=0;i<m;i++)
        {
            p[i] = new int[m];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> p[i][j];
                if(p[i][j] < min)
                {
                    min = p[i][j];
                }
                else if(p[i][j] > max)
                {
                    max = p[i][j];
                }
            }
        }
        cout << min << " " << max << endl;
        t--;
    }

    return 0;
}