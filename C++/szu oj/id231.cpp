//时钟模拟
#include <iostream>
using namespace std;
class Counter
{
    protected:
        int value;
    public:
        Counter()
        {
            value = 0;
        }
        void SetValue(int value_in)
        {
            value = value_in;
        }
        void Increment()
        {
            value++;
        }
        int GetValue()
        {
            return value;
        }
};
class CycleCounter:public Counter
{
    private:
        int min_value;
        int max_value;
    public:
        CycleCounter(int min,int max):Counter()
        {
            min_value = min;
            max_value = max;
        }
        void Increment()
        {
            value++;
        }
        int CarryOver()
        {
            int temp = value;
            temp /= (max_value - min_value + 1);
            if(!temp)
                return 0;
            else 
            {
                value %= (max_value - min_value + 1);
                return temp;
            }
        }
        void Add(int a)
        {
            value += a;
        }
};
class CClock
{
    private:
        CycleCounter hour{0,23};
        CycleCounter minute{0,59};
        CycleCounter second{0,59};
    public:
        CClock(int a,int b,int c)
        {
            hour.SetValue(a);
            minute.SetValue(b);
            second.SetValue(c);
        }
        void Time(int s)
        {
            second.Add(s);
            CarryOver();
        }
        void CarryOver()
        {
            int increment;
            if(increment = second.CarryOver())
            {
                minute.Add(increment);
                if(increment = minute.CarryOver())
                {
                    hour.Add(increment);
                    hour.CarryOver();
                }
            }
        }
        void Print()
        {
            cout << hour.GetValue() << ":"
                 << minute.GetValue() << ":"
                 << second.GetValue() << endl;
        }
        ~CClock()
        {
            cout << "Mamba out" << endl;
        }

};
int main(){

    int n;
    cin >> n;
    while(n > 0)
    {
        int h,m,s,delta;
        cin >> h >> m >> s >> delta;
        CClock jojo(h,m,s);
        jojo.Time(delta);
        jojo.Print();
        n--;
    }

    return 0;
}