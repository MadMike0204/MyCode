#include <iostream>
using namespace std;
int main(){

    int t,month;
    cin >> t;
    char** p1 = new char*[12];
    char months[12][10] = {"January","February","March","April","May","June",
                          "July","August","September","October","November","December"};
    int i;
    for(i=0;i<12;i++)
    {
        p1[i] = &months[i][0];
    }
    while(t>0)
    {
        cin >> month;
        if(month >= 1 && month <= 12)
        {
            for(int i=0;i<10;i++)
            {
                cout << *(p1[month-1]+i);            
            }
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