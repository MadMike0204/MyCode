#include <iostream>
using namespace std;

// template<class T,class D>
// T Max(T a,D b)
// {
//     return (a>b)?a:b;
// }    
// template<class T>
// T Max(T a,T b)
// {
//     return (a>b)?a:b;
// }
// int Max(int a,int b)
// {
//     return (a>b)? a:b;
// }
template<class T>
class MyVar
{
    private:
        T t1,t2,t3;
    public:
        MyVar()
        {
            t1 = t2 = t3 = 0;
        }
        MyVar(T t1,T t2,T t3)
        {
            this->t1 = t1;
            this->t2 = t2;
            this->t3 = t3;
        }
        T getMax()
        {
            if(t1 > t2 && t1 > t3)
            {
                return t1;
            }
            else if(t2 > t1 && t2 > t3)
            {
                return t2;
            }
            else if(t3 > t1 && t3 > t2)
            {
                return t3;
            }
        }
        T getMin();
        
};
int main(){

    // char x = '7';
    // int y = 9;
    // cout << "Max:" << Max<double>(x,y) << endl;
    MyVar<double> jojo(2,2.3,2.333);
    cout << jojo.getMax() << endl;
    cout << "Test" << endl;    

    return 0;
}