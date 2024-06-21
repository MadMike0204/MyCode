#include<iostream>
using namespace std;
int main(){

    int i,temp;
    int* p = new int[200];
    for(i=0;;i++)
    {
        cin >> temp;
        if(temp != 0)
        {
            p[i] = temp;
        }
        else
        {
            break;
        }
    }
    for(i=i-1;i>=0;i--)
    {
        printf(i==0?"%d":"%d ",p[i]);
    }

    return 0;
}