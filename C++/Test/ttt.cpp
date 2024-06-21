#include <iostream>
#include <cmath>
using namespace std;


int sub(int x,int y);

int main(){

    char op;
    int x,y;
    scanf("%d%c%d",&x,&op,&y);
    cout << x+y;

    return 0;
}

int sub(int x,int y)
{
            int result = 0;
            int xx[7] = {0},yy[7] = {0};
            for(int i=0;i<7;i++)
            {
                xx[i] = x % 10;
                yy[i] = y % 10;
                x /= 10;
                y /= 10;
                xx[i] -= yy[i];
                if(xx[i] < 0)
                {
                    xx[i] += 10;
                }
                result += xx[i] * (int)pow(10,i);
            }
            return result;
}