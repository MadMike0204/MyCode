#include <iostream>
using namespace std;

struct rect
{
    struct
    {
        int x1;
        int x2;
        int y1;
        int y2;
    }Rpoint;
};

rect NewRect(int n)
{
    rect newnew;
    cin >> newnew.Rpoint.x1 >> newnew.Rpoint.y1 
        >> newnew.Rpoint.x2 >> newnew.Rpoint.y2;
    return newnew;  
}

void initial_rect(rect &rect1)
{
    int temp;
    if(rect1.Rpoint.x1 > rect1.Rpoint.x2)
    {
        temp = rect1.Rpoint.x1;
        rect1.Rpoint.x1 = rect1.Rpoint.x2;
        rect1.Rpoint.x2 = temp;
    }
    if(rect1.Rpoint.y1 > rect1.Rpoint.y2)
    {
        temp = rect1.Rpoint.y1;
        rect1.Rpoint.y1 = rect1.Rpoint.y2;
        rect1.Rpoint.y2 = temp;
    }
}

bool isoverlap(const rect &rect1,const rect &rect2)
{
    if(rect1.Rpoint.y2 < rect2.Rpoint.y1)
    {
        return 1;
    }
    else if(rect1.Rpoint.x2 < rect2.Rpoint.x1)
    {
        return 1;
    }
    else if(rect1.Rpoint.y1 > rect2.Rpoint.y2)
    {
        return 1;
    }
    else if(rect1.Rpoint.x1 > rect1.Rpoint.x2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(){

    int t;
    cin >> t;
    while(t > 0)
    {
        rect rect1 = NewRect(1);
        rect rect2 = NewRect(2);
        initial_rect(rect1);
        initial_rect(rect2);
        if(isoverlap(rect1,rect2))
        {
            cout << "not overlapped" << endl;
        }
        else
        {
            cout << "overlapped" << endl;
        }
        t--;
    }

    return 0;
}