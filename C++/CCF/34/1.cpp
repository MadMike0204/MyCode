#include <iostream>
using namespace std;

int main(){

    int n,m,p,q,k;
    cin >> n >> m >> p >> q;
    k = n * m;

    int arr[k];
    for(int i=0;i<k;i++)
    {
        cin >> arr[i];
    }
    int idx = 0;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            printf(j==0?"%d":" %d",arr[idx]);
            idx++;
        }
        cout << endl;
    }


    return 0;
}