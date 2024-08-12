#include <iostream>
#include <cstring>
using namespace std;
int main(){

    int l,u,v,m,count=0;
    cin >> l;
    int road[l+1];
    memset(road,0,sizeof(road));
    cin >> m;
    while(m--)
    {
        cin >> u >> v;
        for(int i=u;i<=v;i++)
        {
            road[i]--;
        }
    }
    for(int i=0;i<l+1;i++)
    {
        if(road[i] == 0)
            count++;
    }
    cout << count << endl;

    return 0;
}