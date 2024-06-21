#include <iostream>
using namespace std;

float* search(float (*p)[4], int n)
{ 
    return p[n-1]; 
}

int main()
{ 
    float *p,score[][4]={{60,70,80,90},
                         {56,89,67,88},
                         {34,78,90,66}};
    int i,m;
    cout<<"Enter the number:\n";
    cin>>m;
    cout<<"The scores are:\n";
    p=search(score,m);
    for(i=0;i<4;i++)
    cout<<p[i]<<" ";

    return 0;
}