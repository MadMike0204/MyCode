#include <iostream>
#include <cstring>
using namespace std;

int max(int x,int y);
int min(int x,int y);
int add(int x,int y);
void process(int x,int y,int (*func)(int,int));

int main(){

    int a = 2,b = 9,c = 0;
    process(2,9,add);

    return 0;
}

int max(int x,int y)
{
    return (x>y? x:y);
}
int min(int x,int y)
{
    return (x<y? x:y);
}
int add(int x,int y)
{
    return (x+y);
}
void process(int x,int y,int (*func)(int,int))
{
    int result;
    result = (*func)(x,y);
    cout << result << endl;
}