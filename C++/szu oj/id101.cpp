#include <iostream>
using namespace std;

static string tname[5] = {"0","BF","CD","VCD","DVD"};
static string sname[2] = {"not rented","rented"};

class CV
{
    private:
        int type,rent;
        bool state;
        string name;
    public:
        CV()
        {
            cin >> type >> name >> rent >> state;
        }
        void Print(int opcode)   
        {
            cout << tname[type] << "[" << name << "]" << sname[state] << endl;
            if(opcode)
            {
                if(!state)
                {
                    cout << "No rental" << endl;
                }
                else
                {
                    cout << "Rental: " << Fee(opcode) << endl;
                }
            }
        }
        int Fee(int day)
        {
            return rent * day;
        }
};
int main(){

    int t,num;
    cin >> t;
    while(t--)
    {
        CV jojo;
        cin >> num;
        jojo.Print(num);
    }


    return 0;
}