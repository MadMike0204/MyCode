#include <iostream>
using namespace std;

// 点类
class CPoint {
private:
    int x;
    int y;
public:
    CPoint(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    
    int getX() const { return x; }
    int getY() const { return y; }
};

// 矩形类
class CRect {
private:
    CPoint leftTop;     // 左上角点
    CPoint rightBottom; // 右下角点
    
public:
    CRect(const CPoint& p1, const CPoint& p2) {
        // 确保leftTop是左上角，rightBottom是右下角
        int left = min(p1.getX(), p2.getX());
        int right = max(p1.getX(), p2.getX());
        int top = max(p1.getY(), p2.getY());
        int bottom = min(p1.getY(), p2.getY());
        
        leftTop = CPoint(left, top);
        rightBottom = CPoint(right, bottom);
    }
    
    // 友元函数声明
    friend bool isOverlapped(const CRect& r1, const CRect& r2);
};

// 判断两个矩形是否重叠的友元函数
bool isOverlapped(const CRect& r1, const CRect& r2) {
    // 检查一个矩形是否在另一个矩形的左侧、右侧、下方或上方
    if (r1.rightBottom.getX() < r2.leftTop.getX() ||    // r1在r2左侧
        r1.leftTop.getX() > r2.rightBottom.getX() ||    // r1在r2右侧
        r1.rightBottom.getY() > r2.leftTop.getY() ||    // r1在r2上方
        r1.leftTop.getY() < r2.rightBottom.getY())      // r1在r2下方
    {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        
        CPoint p1(x1, y1);
        CPoint p2(x2, y2);
        CPoint p3(x3, y3);
        CPoint p4(x4, y4);
        
        CRect rect1(p1, p2);
        CRect rect2(p3, p4);
        
        if (isOverlapped(rect1, rect2)) {
            cout << "overlapped" << endl;
        } else {
            cout << "not overlapped" << endl;
        }
    }
    
    return 0;
}
