#include <iostream>
using namespace std;
class polygon
{ 
    protected:
        int number;//边数，最多不超过100条边
    private:
        int sides[100];//边长数组
    public:
        polygon(int number_in,int* sides_in):
            number(number_in)
        {
            if(sides_in == NULL)
            {
                return;
            }
            for(int i=0;i<number;i++)
            {
                sides[i] = sides_in[i];                
            }
        }
        int perimeter()            //计算多边形边长
        {
            int perimeter = 0;
            for(int i=0;i<number;i++)
            {
                perimeter += sides[i];
            }
            return perimeter;
        }
        void display()//输出多边形边数和周长
        {
            cout << number << " "
                 << perimeter() << endl;
        }
};
class rectangle:public polygon
{
    protected:
        int height;
        int width;
    public:
        rectangle(int height_in,int width_in):
            polygon(4,NULL),height(height_in),width(width_in){}
        
        int perimeter()
        {
            return (height + width) * 2;
        }
        void display()
        {
            cout << number << " "
                 << perimeter() << endl;
        }
};
class equal_polygon:public polygon
{
    protected:
        int side_len;
    public:
        equal_polygon(int number_in,int side_len_in):
            polygon(number_in,NULL),side_len(side_len_in){}
        int perimeter()
        {
            return number * side_len;
        }
        void display()
        {
            cout << number << " "
                 << perimeter() << endl;
        }
};

int main(){

    int n;
    cin >> n;
    while(n > 0)
    {
        int type,a,b;
        cin >> type;
        if(type == 1)
        {
            cin >> a >> b;
            rectangle jostar(a,b);
            jostar.display();
        }
        else if(type == 2)
        {
            cin >> a >> b;
            equal_polygon jostar(a,b);
            jostar.display();
        }
        else
        {
            int sides[100];
            for(int i=0;;)
            {
                cin >> a;
                if(a == -1)
                {
                    b = i;
                    break;
                }
                sides[i] = a;
                i++;
            }
            polygon jostar(b,sides);
            jostar.display();
        }

        n--;
    }

    return 0;
}