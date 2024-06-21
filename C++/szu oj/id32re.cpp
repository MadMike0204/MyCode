#include <iostream>
#include <cstring>
using namespace std;
int main(){

    int t,month;
    cin >> t;
    string** p1 = new string*[12];
    string monthh[12] = {"January","February","March","April","May","June",
                          "July","August","September","October","November","December"};
    int i;
    for(i=0;i<12;i++)
    {
        p1[i] = &monthh[i];
    }
    while(t>0)
    {
        cin >> month;
        if(month >= 1 && month <= 12)
        {

            cout << *p1[month-1];   

            cout << endl; 
        }
        else
        {
            cout << "error" << endl; 
        }
        t--;
    }
    return 0;
}