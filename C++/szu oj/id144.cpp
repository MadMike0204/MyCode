#include<iostream>
using namespace std;

class Tree{
    private:
        int ages;
    public:
        Tree(){
            ages = 1;
        }
        Tree(int ages){
            this->ages = ages;
        }
        void grow(int years){
            ages += years;
        }
        void age(){
            cout << ages << endl;
        }
};

int main(){

    Tree t1;
    int t;
    cin >> t;
    t1.grow(t);
    t1.age();

    int year;
    cin >> year >> t;
    Tree t2(year);
    t2.grow(t);
    t2.age();

    return 0;
}