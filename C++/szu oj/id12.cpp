#include <iostream>
using namespace std;
int main(){

    int t,N,M;
    static int arr[45][45];
    cin >> t;
    while(t>0)
    {
        cin >> N >> M;
        int i,j;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                cin >> arr[i][j];
            }
        }
        for(j=M-1;j>=0;j--)
        {
            for(i=0;i<N;i++)
            {
                printf(i==0?"%d":" %d",arr[i][j]);
            }
            cout << endl;
        }
        t--;
    }

    return 0;
}