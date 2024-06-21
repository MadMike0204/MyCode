#include <iostream>
using namespace std;
int main(){
    double t;
    int n;
    cin>>t>>n;
    t = t * 1.0 / n;
    n = 2 * n;
    printf("%.3lf\n%d\n",t,n);

    return 0;
}