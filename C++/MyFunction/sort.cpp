#include <iostream>
#include <functional>
using namespace std;
/*有一个node类型的数组node arr[100]，想对它进行排序：
先按a值升序排列，如果a值相同，再按b值降序排列，
如果b还相同，就按c降序排列。
就可以写这样一个比较函数：
*/
bool cmp(node x,node y)
{
    if(x.a!=y.a) return x.a>y.a;
    if(x.b!=y.b) return x.b>y.b;
    return x.c>y.c;
}
int main(){

    node arr[99];

    return 0;
}
