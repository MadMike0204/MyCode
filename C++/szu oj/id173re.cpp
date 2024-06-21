#include <iostream>
using namespace std;
class CRect;
class CPoint
{
    friend CRect;
    friend bool isoverlap(const CRect &R1,const CRect &R2);
    private:
        int x,y;
    public:
        CPoint(int x_in,int y_in)
        {
            x = x_in;
            y = y_in;
        }
        CPoint()
        {
            x = 0;
            y = 0;
        }
};
class CRect
{
    friend bool isoverlap(const CRect &R1,const CRect &R2);
    private:
        CPoint *P1;
        CPoint *P2;
    public:
        CRect(const CPoint &p1,const CPoint &p2)
        {
            P1 = new CPoint(p1);
            P2 = new CPoint(p2);
        }
        void initial_Rect()
        {
            int temp;
            if(P1->x > P2->x)
            {
                temp = P1->x;
                P1->x = P2->x;
                P2->x = temp;
            }
            if(P1->y > P2->y)
            {
                temp = P1->y;
                P1->y = P2->y;
                P2->y = temp;
            }
        }
        ~CRect()
        {
            if(P1 != NULL)
            {
                delete P1;
            }
            if(P2 != NULL)
            {
                delete P2;
            }
            P1 = NULL;
            P2 = NULL;
        }
};

bool isoverlap(const CRect &R1,const CRect &R2)
{
    if(R1.P2->y < R2.P1->y)
    {
        return 0;
    }
    else if(R1.P2->x < R2.P1->x)
    {
        return 0;
    }
    else if(R1.P1->y > R2.P2->y)
    {
        return 0;
    }
    else if(R1.P1->x > R1.P2->x)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(){

    int t;
    cin >> t;
    while(t > 0)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        CPoint R1_p1(x1,y1);
        CPoint R1_p2(x2,y2);
        cin >> x1 >> y1 >> x2 >> y2;
        CPoint R2_p1(x1,y1);
        CPoint R2_p2(x2,y2);
        CRect Rect1(R1_p1,R1_p2);
        CRect Rect2(R2_p1,R2_p2);
        Rect1.initial_Rect();
        Rect2.initial_Rect();
        if(isoverlap(Rect1,Rect2))
        {
            cout << "overlapped" << endl;
        }
        else
        {
            cout << "not overlapped" << endl;
        }
        t--;
    }  
    return 0;
}
