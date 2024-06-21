#include<iostream>
using namespace std;

class Joker{
    public:
        Joker(string name,int year,int girls)
        {
            joname = name;
            joyear = year;
            jogirls = girls;
        }
        void infoJoker()
        {
            cout << "Joker's name:" << joname << endl
                 << "Joker's year:" << joyear << endl
                 << "Joker's girls:" << jogirls << endl;
        }
        void getJoker()
        {
            cin >> joname >> joyear >> jogirls;
        }
    private:
        string joname;
        int joyear;
        int jogirls;

};

int main(){

    Joker newnew("Jostar",18,233);
    newnew.infoJoker();
    Joker* newzhi = new Joker("JoJo",18,2333);
    newzhi->infoJoker();


    return 0;
}