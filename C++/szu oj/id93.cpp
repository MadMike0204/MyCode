#include <iostream>
#include <cmath>
using namespace std;

class CSieve
{
    private:
        int* p_sieve;
        unsigned long num;
    public:
        CSieve(unsigned long n)
        {
            num = n;
            p_sieve = new int[num+1];
            for(int i=0;i<=num;i++)
            {
                *(p_sieve+i) = 1;
            }
            p_sieve[0] = p_sieve[1] = 0;
        }
        void printPrime()
        {
            for(int i=2;i<=num;i++)
            {
                if(*(p_sieve+i))
                {
                    printf(i==2?"%d":" %d",i);
                }
            }
            cout << endl;
        }
        void getOut()
        {
            int n;
            bool flag;
            for(int i=2;i<=num;i++)
            {
                flag = 1;
                for(int j=2;j<i;j++)
                {
                    if(i%j == 0)
                    {
                        flag = 0;
                    }
                }
                if(flag)
                {
                    n = 2;
                    while(i*n <= num)
                    {
                        p_sieve[i*n] = 0;
                        n++;
                    }
                }
            }
        }
        ~CSieve()
        {
            delete p_sieve;
        }
};

int main(){

    int t;
    cin >> t;
    while(t > 0)
    {
        int n;
        cin >> n;
        CSieve newnew(n);
        newnew.getOut();
        newnew.printPrime();
        t--;
    }

    return 0;
}