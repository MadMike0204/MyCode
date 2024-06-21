#include <iostream>
#include <string>
using namespace std;
int main(){

    int t,n;
    cin >> t;
    cin.get();
    char a,b,temp;
    while(t>0)
    {
        cin >> a >> temp;
        cin.get();
        cin >> n;
        cin.get();
        cin >> b;
        cin.get();
        int i;
        if(temp == '-')
        {
            cout << a;
            for(i=0;i<n-1;i++)
            {
                cout << b;
            }
            cout << endl;
        }
        else if(temp == '+')
        {
            for(i=0;i<n-1;i++)
            {
                cout << b;
            }
            cout << a;
            cout << endl;
        }
        t--;
    }

    return 0;
}
