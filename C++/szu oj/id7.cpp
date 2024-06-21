#include <iostream>
#include <algorithm>
using namespace std;
int main(){

    int T,A[3] = {0},B[3] = {0};
    cin >> T;
    while(T > 0)
    {
        bool X = 1;
        int i,suma = 0,sumb = 0;
        for(i=0;i<3;i++)
        {
            cin >> A[i];
            suma += A[i];
        }
        for(i=0;i<3;i++)
        {
            cin >> B[i];
            sumb += B[i];
        }
        sort(A,A+3);
        sort(B,B+3);
        if(suma > sumb)
        {
            for(i=0;i<3;i++)
            {
                if(A[i] < B[i])
                {
                    X = 0;
                }
            }
        }
        else if(suma < sumb)
        {
            for(i=0;i<3;i++)
            {
                if(A[i] > B[i])
                {
                    X = 0;
                }
            }
        }
        else if(suma == sumb)
        {
            for(i=0;i<3;i++)
            {
                if(A[i] != B[i])
                {
                    X = 0;
                }
            }
        }
        if(X == 1)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        T--;
    }

    return 0;
}