#include<iostream>
using namespace std;

struct acm
{
    long num;
    string id;
};

acm Newacm(int n)
{
    acm newnew;
    cin >> newnew.id >> newnew.num;
    return newnew;
}

void sort_acm(int t,acm (&Nacm)[])
{
    acm temp;
    int flag = true;
    while(flag)
    {
        flag = 0;
        for(int i=0;i<t-1;i++)
        {
            if(Nacm[i].num < Nacm[i+1].num)
            {
                flag = 1;
                temp = Nacm[i];
                Nacm[i] = Nacm[i+1];
                Nacm[i+1] = temp;
            }
        }
    }
}

void print_acm(int t,acm (&Nacm)[])
{
    for(int i=0;i<t;i++)
    {
        cout << Nacm[i].id << " " << Nacm[i].num << endl;
    }
}

int main(){

    int t;
    cin >> t;
    acm Nacm[t];

    for(int i=0;i<t;i++)
    {
        Nacm[i] = Newacm(i);
    }
    sort_acm(t,Nacm);
    print_acm(t,Nacm);

    return 0;
}