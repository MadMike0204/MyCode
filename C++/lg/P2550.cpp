#include <iostream>
#include <cstring>
using namespace std;
class Lottery
{
    private:
        int arr[7];
    public:
        static int result[7];
    public:
        Lottery()
        {
            for(int i=0;i<7;i++)
            {
                cin >> arr[i];
            }
        }
        bool operator == (Lottery& a)
        {
            bool flag = 1;
            for(int i=0;i<7;i++)
            {
                if(this->arr[i] != a.arr[i])
                {
                    flag = 0;
                    break;
                }
            }
            return flag;
        }
        void Compare(Lottery&a,Lottery&b)
        {
            int n=0;
            for(int i=0;i<7;i++)
            {
                for(int j=0;j<7;j++)
                {
                    if(a.arr[i] == b.arr[j])
                    {
                        n++;
                    }
                }
            }
            if(!n)
                return;
            result[7-n]++;
        }
};
int Lottery::result[7] = {0,0,0,0,0,0,0};

int main(){

    int n,num = 0;
    cin >> n;
    Lottery aim;
    for(int i=0;i<n;i++)
    {
        Lottery m;
        aim.Compare(aim,m);
    }

    for(int i=0;i<6;i++)
    {
        cout << Lottery::result[i] << " ";
    }
    cout << Lottery::result[6] << endl;
    return 0;
}