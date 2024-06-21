#include <iostream>
#include <cstring>
using namespace std;

int main(){

    char *p = new char[8];
    char *x = new char[10];
    cin >> p;
    cin >> x;
    char *temp = new char[18];

    strcpy(temp,p);
    strcpy(temp,x);
    cout << temp << endl;

    return 0;
}