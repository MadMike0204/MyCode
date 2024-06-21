#include <iostream>
#include <cmath>
using namespace std;

int FuncNum(const int m,const int n);

int main(){

    int t,N,M,result;
    cin >> t;
    while(t>0)
    {
        cin >> N >> M;
        result = FuncNum(M,N);
        cout << result << endl;
        t--;
    }

    return 0;
}

int FuncNum(const int m,const int n)
{
    int i,X;
    long a=1,b=1,c=1;
    for(i=1;i<=n;i++)
    {
        a *= i;
    }
    for(i=1;i<=m;i++)
    {
        b *= i;
    }
    for(i=1;i<=n-m;i++)
    {
        c *= i;
    }
    X = a / (b * c);
    
    return X;
}