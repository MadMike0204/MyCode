#include <iostream>
#include <cstring>
using namespace std;

class Bit4
{
    private:
        int bit0,bit1,bit2,bit3;
    public:
        Bit4(int b3,int b2,int b1,int b0):
            bit3(b3),bit2(b2),bit1(b1),bit0(b0){}
        Bit4 operator + (Bit4 &x)
        {
            int div;
            this->bit0 += x.bit0;
            div = bit0 / 4;
            bit0 %= 4;

            this->bit1 += (x.bit1 + div);
            div = bit1 / 4;
            bit1 %= 4;

            this->bit2 += (x.bit2 + div);
            div = bit2 / 4;
            bit2 %= 4;

            this->bit3 += (x.bit3 + div);
            div = bit3 / 4;
            bit3 %= 4;
            
            return *this;
        }
        void print()
        {
            if(bit3 != 0)
            {
                cout << bit3 << bit2 << bit1 << bit0 << endl;
            }
            else if(bit2 != 0)
            {
                cout << bit2 << bit1 << bit0 << endl;
            }
            else if(bit1 != 0)
            {
                cout << bit1 << bit0 << endl;
            }
            else
            {
                cout << bit0;
            }
        }
};

void to_arr(int x,int arr[4])
{
    for(int i=0;i<4;i++)
    {
        arr[i] = x % 10;
        x /= 10;
    }
}

int main(){

    int t,x;
    int arr[4];
    cin >> t;
    cin >> x;
    to_arr(x,arr);
    Bit4 result(arr[3],arr[2],arr[1],arr[0]);
    memset(arr,0,sizeof(arr));
    while(t > 1)
    {
        cin >> x;
        to_arr(x,arr);
        Bit4 in(arr[3],arr[2],arr[1],arr[0]);
        memset(arr,0,sizeof(arr));
        result = result + in;
        t--;
    }

    result.print();

    return 0;
}