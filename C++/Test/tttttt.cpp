#include <iostream>
using namespace std;
int main(){

    int i,j;
    i = j = 1;
    while(i <= j)
    {
        i++;
        j *= 2;
        cout << "i:" << i
             << " j:" << j << endl;
    }


    return 0;
}