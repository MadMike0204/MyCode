#include <iostream>
using namespace std;

class CRectangle
{
    private:
        int x1,x2,y1,y2;
    public:
        CRectangle(int x1,int y1,int x2,int y2)
        {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }
        operator int() const
        {
            return (x2 - x1) * (y1 - y2);
        }
        bool operator == (const CRectangle &r)
        {
            if(x1 == r.x1 && x2 == r.x2 && y1 == r.y1 && y2 == r.y2)
            {
                return 1;
            }
            return 0;
        }
        bool operator > (const CRectangle &r)
        {
            if(x1 <= r.x1 && y1 >= r.y1 && x2 >= r.x2 && y2 <= r.y2 && !(*this == r))
            {
                return 1;
            }
            else 
                return 0;
        }
        bool operator * (const CRectangle &r)
        {
            if(y2 > r.y1)
                return 0;
            if(y1 < r.y2)
                return 0;
            if(x2 < r.x1)
                return 0;
            if(x1 > r.x2)
                return 0;
            return 1;
        }
        friend ostream & operator << (ostream & stream,
                                      const CRectangle &r);
};
ostream & operator << (ostream & stream,
                                      const CRectangle &r)
{
    cout << r.x1 << " " << r.y1 << " " << r.x2 << " " << r.y2;
    return stream;
}

int main (){

    int t,x1,x2,y1,y2;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2;
        CRectangle rect1(x1,y1,x2,y2);
        cin>>x1>>y1>>x2>>y2;	//矩型2的左上角、右下角	
        CRectangle rect2(x1,y1,x2,y2);

        cout<<"矩形1:" <<rect1<<" "<<(int) rect1<<endl;	//输出矩形1的坐标及面积	
        cout<<"矩形2:" <<rect2<<" "<<(int) rect2<<endl;	//输出矩加2的坐标及面积	

        if(rect1==rect2)//判断两个矩形相的	
            cout<<"矩形1和矩形2相等"<<endl;
        else if(rect2>rect1)		
            cout<<"矩形2包含矩形1"<<endl; 
        else if (rect1>rect2)
            cout<<"矩形1包含矩形2"<<endl;
        else if (rect1*rect2)	
            cout<<"矩形1和矩形2相交"<<endl; 
        else
            cout<<"矩形1和矩形2不相交"<<endl; 
        cout<<endl;
    }
    
    return 0;
}