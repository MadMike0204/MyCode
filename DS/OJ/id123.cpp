#include<iostream>
#include<queue>
using namespace std;
struct guest{
    char type;
    int time;
    guest(char typ = 0,int t = 0):type(typ),time(t){}
};

int main(){

    queue<guest> gs1;
    queue<guest> gs2;
    int t;
    cin >> t;
    char type;
    int time;
    guest temp;
    int A,B,C,iA,iB,iC;
    iA = iB = iC = 0;
    A = B = C = 0;

    for(int i=0;i<t;i++)
    {
        cin >> type;
        gs1.push(guest(type));
        switch (type)
        {
        case 'A':
            iA++;
            break;
        case 'B':
            iB++;
            break;
        default:
            iC++;
            break;
        }
    }
    for(int i=0;i<t;i++)
    {
        cin >> time;
        temp = gs1.front();
        gs1.pop();
        gs2.push(guest(temp.type,time));
    }
    for(int i=0;i<t;i++)
    {
        temp = gs2.front();
        gs2.pop();
        switch (temp.type)
        {
        case 'A':
            A += temp.time;
            break;
        case 'B':
            B += temp.time;
            break;
        default:
            C += temp.time;
            break;
        }
    }

    cout << A/iA << endl << B/iB << endl << C/iC << endl;

    return 0;
}