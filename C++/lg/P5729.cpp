#include <iostream>
#include <cstring>
using namespace std;
int main(){

    int length,width,height,N,V=0;
    cin >> length >> width >> height;
    cin >> N;
    int Pixel[length+1][width+1][height+1];
    memset(Pixel,0,sizeof(Pixel));
    int x1,x2,y1,y2,z1,z2;
    while(N--)
    {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for(int i=x1;i<=x2;i++)
        {
            for(int j=y1;j<=y2;j++)
            {
                for(int k=z1;k<=z2;k++)
                {
                    Pixel[i][j][k]--;
                }
            }
        }
    }
    for(int i=1;i<=length;i++)
    {
        for(int j=1;j<=width;j++)
        {
            for(int k=1;k<=height;k++)
            {
                if(Pixel[i][j][k] == 0)
                    V++;
            }
        }
    }
    cout << V << endl;

    return 0;
}