#include <iostream>
using namespace std;

void search(int* num,int n,int* nmax,int* nmaxindex);
void input(int *num,int n);

int main(){

    int t,n,nmax,nmaxindex;
    int* to_nmax = &nmax;
    int* to_nmaxindex = &nmaxindex;
    cin >> t;
    while(t > 0)
    {
        cin >> n;
        int arr[n];
        int* p = &arr[0];
        for(int i=0;i<n;i++)
        {
            input(p,i);
        }
        search(p,n,to_nmax,to_nmaxindex);
        cout << *to_nmax << " " << *to_nmaxindex << endl;
        t--;
    }

    return 0;
}

void search(int* num,int n,int* nmax,int* nmaxindex)
{
    int max = -9999;
    int index;
    for(int i=0;i<n;i++)
    {
        if(*(num+i) > max)
        {
            max = *(num+i);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(max == *(num+i))
        {
            index = i;
            break;
        }
    }
    *nmax = max;
    *nmaxindex = index;
}
void input(int *num,int n)
{
    cin >> *(num+n);
    return;
}