#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
void Pardon(bool** matrix,int n,int x0,int y0)
{
    int k = exp2(n-1);
    for(int i=x0;i<x0+exp2(n-1);i++)
    {
        for(int j=y0;j<y0+exp2(n-1);j++)
        {
            matrix[i][j] = 1;
        }
    }
    n--;
    if(n == 0)
        return;
    Pardon(matrix,n,x0+exp2(n),y0);
    Pardon(matrix,n,x0,y0+exp2(n));
    Pardon(matrix,n,x0+exp2(n),y0+exp2(n));
}

int main(){

    int n;
    cin >> n;
    int k = exp2(n);
    bool** matrix = new bool*[k];
    for(int i=0;i<k;i++)
    {
        matrix[i] = new bool[k];
        memset(matrix[i],0,k*sizeof(bool));
    }
    Pardon(matrix,n,0,0);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            printf(j==0?"%d":" %d",!matrix[i][j]);
        }
        cout << endl;
    }

    return 0;
}

/*
不知名解法
#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin>>n;
	for(int i=0; i<(1<<n); i++) {
		for(int j=0; j<(1<<n); j++) {
			printf("%d ",(i|j)!=((1<<n)-1)?0:1);
		}
		cout<<endl;
	}
}
*/