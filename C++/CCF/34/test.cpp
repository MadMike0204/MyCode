#include <iostream>
using namespace std;
int main(){

    string** jojo = new string*[5];

    for(int i=0;i<5;i++)
    {
        jojo[i] = new string[20];
        cin >> *(jojo[i]);
    }
    for(int i=0;i<5;i++)
    {
        cout << *(jojo[i]) << endl;
    }

    return 0;
}