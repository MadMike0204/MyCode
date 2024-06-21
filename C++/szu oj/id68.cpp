#include<iostream>
using namespace std;
int main(){

    int t,length,sum,avg;
    double min = 9999.9;
    char maxc = 'A';
    char whatkind;
    cin >> t;
    while(t>0)
    {
        cin >> whatkind;
        cin.get();
        cin >> length;

        if(whatkind == 'I')
        {
            int* p = new int[length];
            for(int i=0;i<length;i++)
            {
                cin >> *(p+i);
                sum += *(p+i);
            }
            avg = sum / length;
            cout << avg << endl;
        }

        else if(whatkind == 'F')
        {
            double* p = new double[length];
            for(int i=0;i<length;i++)
            {
                cin >> *(p+i);
                if(*(p+i) < min)
                {
                    min = *(p+i);
                }
            }
            cout << min;
        }

        else if(whatkind == 'C')
        {
            char* p = new char[length];
            for(int i=0;i<length;i++)
            {
                cin >> *(p+i);
                if(*(p+i) > maxc)
                {
                    maxc = *(p+i);
                }
            }
            cout << maxc << endl;
        }

        t--;
    }

    return 0;
}