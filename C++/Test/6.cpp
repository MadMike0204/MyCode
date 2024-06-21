#include <iostream>
using namespace std;

class A
{
    public:
        
        int id;
        A(int id_in)
        {
            id = id_in;
        }
};
int main(){

    A jojo(233);
    A ne(99);
    ne = jojo;
    jojo.id = 0;
    cout << ne.id << endl;


    return 0;
}