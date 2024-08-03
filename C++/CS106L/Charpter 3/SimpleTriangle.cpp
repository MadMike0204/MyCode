#include <iostream>
#include <iomanip>
using namespace std;

void DrawTriangle(int x,char c)
{
    for(int i=0;i<x;i++)
    {
        cout << setw(x-i) << setfill(' ') << ' ';
        cout << setw(i*2+1) << setfill(c) << c;
        cout << endl;
    }
}

int main(){

    DrawTriangle(7,'$');

    return 0;
}