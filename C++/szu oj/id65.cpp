#include <iostream>
using namespace std;
int main(){

    int a,b;
    while(cin >> a)
    {
        int arr1[a];
        for(int i=0;i<a;i++)
        {
            cin >> arr1[i];
        }
        cin >> b;
        int arr2[b];
        for(int i=0;i<b;i++)
        {
            cin >> arr2[i];
        }

        int* p1 = &arr1[0];
        int* p2 = &arr2[0];

        int res[a+b],m = 0,n = 0;
        for(int i=0;i<a+b;i++)
        {
            if(*(p1) <= *(p2) && m != a)
            {
                res[i] = *(p1);
                p1++;
                m++;    
            }
            else if(*(p1) <= *(p2) && m == a && n != b)
            {
                res[i] = *(p2);
                p2++;
                n++;
            }
            else if(*(p1) > *(p2) && n != b)
            {
                res[i] = *(p2);
                p2++;
                n++;    
            }
            else if(*(p1) > *(p2) && n == b && m != a)
            {
                res[i] = *(p1);
                p1++;
                m++; 
            }
        }
        //输出
        cout << a+b << endl;
        for(int i=0;i<a+b;i++)
        {
            printf(i==0?"%d":" %d",res[i]);
        }
        cout << endl << endl;
    }

    return 0;
}