#include <iostream>
#include <algorithm>
using namespace std;

class CPoint {
public:
    double x, y, z;
    
    CPoint(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    
    ~CPoint() {}
};

class CCube {
public:
    CPoint *point;
    
    CCube(double x1, double y1, double z1, double x2, double y2, double z2) {
        point = new CPoint[2];
        point[0] = CPoint(x1, y1, z1);
        point[1] = CPoint(x2, y2, z2);
    }
    
    int collide(CCube &r) {
        double minX1 = min(point[0].x, point[1].x);
        double maxX1 = max(point[0].x, point[1].x);
        double minY1 = min(point[0].y, point[1].y);
        double maxY1 = max(point[0].y, point[1].y);
        double minZ1 = min(point[0].z, point[1].z);
        double maxZ1 = max(point[0].z, point[1].z);
        
        double minX2 = min(r.point[0].x, r.point[1].x);
        double maxX2 = max(r.point[0].x, r.point[1].x);
        double minY2 = min(r.point[0].y, r.point[1].y);
        double maxY2 = max(r.point[0].y, r.point[1].y);
        double minZ2 = min(r.point[0].z, r.point[1].z);
        double maxZ2 = max(r.point[0].z, r.point[1].z);
        
        if (maxX1 < minX2 || minX1 > maxX2) return 0;
        if (maxY1 < minY2 || minY1 > maxY2) return 0;
        if (maxZ1 < minZ2 || minZ1 > maxZ2) return 0;
        
        return 1;
    }
    
    ~CCube() {
        delete[] point;
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        double x1, y1, z1, x2, y2, z2;
        
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        CCube cube1(x1, y1, z1, x2, y2, z2);
        
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        CCube cube2(x1, y1, z1, x2, y2, z2);
        
        if (cube1.collide(cube2)) {
            cout << "collide" << endl;
        } else {
            cout << "have distance" << endl;
        }
    }
    
    return 0;
}
