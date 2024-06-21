#include <iostream>
#include <cmath>
using namespace std;

class XGraph
{
    private:
        int scale;
    public:
        XGraph(int x=1):scale(x){}
        void print()
        {
            int temp;
            for(int i=0;i<scale;i++)
            {
                if(i <= scale/2+1)
                {
                    for(int j=0;j<i-1;i++)
                    {
                        cout << " ";
                    }
                    
                }
                
            }
        }
};