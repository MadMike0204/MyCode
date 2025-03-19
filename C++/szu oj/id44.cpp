#include <iostream>
using namespace std;

void ffind(int* num,int n,int &minindex,int &maxindex)
{
    int max = -9999,min = 9999;
    int maxind,minind;
    for(int i=0;i<n;i++)
    {
        if(*(num+i) > max)
        {
            max = *(num+i);
            maxind = i;
        }
        if(*(num+i) < min)
        {
            min = *(num+i);
            minind = i;
        }
    }
    maxindex = maxind;
    minindex = minind;
}

int main(){

    int n,t;
    int min = 0,max = 0;  
    cin >> t;
    while(t>0)
    {   
        cin >> n;
        int num[n];
        for(int i=0;i<n;i++)
        {
            cin >> num[i];
        }
        ffind(num,n,min,max);
        cout << "min=" << num[min] << " minindex=" << min << endl
             << "max=" << num[max] << " maxindex=" << max << endl;
        t--;
        if(t)
        {
            printf("\n");
        }
    }

    return 0;
}