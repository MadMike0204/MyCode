#include<iostream>
#include<cmath>
using namespace std;

class Point{
    friend double Distance(Point&,Point&);
    private:
        double x,y;
    public:
        Point(double xx,double yy){
            x = xx;
            y = yy;
        }
};
double Distance(Point& a,Point& b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

int main(){

    int t;
    double m,n,p,q;
    cin >> t;
    while(t--){
        cin >> m >> n >> p >> q;
        Point a(m,n);
        Point b(p,q);
        double distance = Distance(a,b);
        cout << (int)distance << endl;
    }

    return 0;
}