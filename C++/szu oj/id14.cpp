#include <iostream>
using namespace std;

int Num(const int N);

int main(){

    int t,Nu;
    cin >> t;
    while(t>0)
    {
        cin >> Nu;
        cout << Num(Nu) << endl;
        t--;
    }

    return 0;
}

int Num(const int N)
{
    int count = 0;
    int i;
    for(i=1;i<=N;i++)
    {
        if(i % 3 != 0 && i % 4 != 0 && i % 7 == 0)
        {
            count++;
        }
    }

    return count;
}