#include <iostream>

using namespace std;

class CC
{
    private:
        int num;
    public:
        CC()
        {
            num = 0;
            cout << "Constructed by default, value = 0" << endl;
        }
        CC(int value)
        {
            num = value;
            cout << "Constructed using one argument constructor, value = " << num << endl;
        }
        CC(CC &p)
        {
            num = p.num;
            cout << "Constructed using copy constructor, value = "<< num << endl;
        }
};

int main(){

    int t;
    cin >> t;
    while(t > 0)
    {
        int in1,in2;
        cin >> in1;

        if(in1 == 0)
        {
            CC newnew;
        }
        else if(in1 == 1)
        {
            cin >> in2;
            CC newnew(in2);
        }
        else if(in1 == 2)
        {
            cin >> in2;
            CC newnew(in2);
            CC newzi(newnew);
        }

        t--;
    }


    return 0;
}