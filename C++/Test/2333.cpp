#include<vector>
#include<iostream>
using namespace std;
int main(){



    int T = 1;
    while(T--)
    {
    }
    vector<int> v = {1,2,3};
    cout << v.size();
    v[0] = 0;
    cout << v[0] << endl;
    v[1] = 1;
    cout << v[1] << endl;
    return 0;
}