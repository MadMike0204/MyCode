#include<iostream>
#include<algorithm>
using namespace std;
int main(){

    int n,L,R,sum = 0;
    cin >> n;
    int arr[n+1];
    int i;
    for(i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    cin >> L >> R;
    for(i=L;i<=R;i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;

    return 0;
}