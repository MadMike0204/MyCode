#include<iostream>
using namespace std;
int main(){

    int t;

    int arr[3],temp;
    int* p1 = &arr[0];
    int* p2 = &arr[1];
    int* p3 = &arr[2];

    cin >> t;
    while(t>0)
    {
        for(int i=0;i<3;i++)
        {
            cin >> arr[i];
        }
        for(int j=0;j<2;j++)
        {
            for(int i=0;i<2;i++)
            {
                if(*(p1+i) < *(p1+i+1))
                {
                    temp = *(p1+i);
                    *(p1+i) = *(p1+i+1);
                    *(p1+i+1) = temp;
                }
            }
        }
        cout << *p1 << " "
             << *p2 << " "
             << *p3 << " " << endl;
    
        t--;
    }
    
    return 0;
}