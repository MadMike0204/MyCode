#include <iostream>
using namespace std;
int main(){

    int t,N,M;
    cin >> t;
    int** arr;
    while(t>0)
    {
        cin >> N >> M;
        arr = new int*[N];
        for(int i=0;i<M;i++){
            arr[i] = new int[M];
        }

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