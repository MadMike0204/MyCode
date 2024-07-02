#include <iostream> 
using namespace std;
class Cstudent
{
    private:
        string name,id,major,institude,gender,living,tel;
    public:
        Cstudent()
        {
            cin >> name >> id >> institude >> major >> gender >> living >> tel;
        }
        void Print()
        {
            cout << name << " "
                 << id << " "
                 << institude << " "
                 << major << " "
                 << gender << " "
                 << living << " "
                 << tel << endl;
        }
};

int main(){

    int t;
    cin >> t;
    while(t--)
    {
        Cstudent jojo;
        jojo.Print();
    }

    return 0;
}