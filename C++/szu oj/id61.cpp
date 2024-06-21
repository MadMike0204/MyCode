#include <iostream>
using namespace std;

struct acm
{
    string id;
    int num;
};

acm newAcm(int n)
{
    acm Stt;
    cin >> Stt.id >> Stt.num;
    return Stt;
}

void printacm(int t,acm (&jojo)[])
{
    for(int i=0;i<t;i++)
    {
        cout << jojo[i].id << " " << jojo[i].num << endl;
    }
}

void sort(int t, acm (&jojo)[])
{
    int i,j;
    acm temp;
    for(i=0;i<t-1;i++)
    {
        int k = i;
        for(j=k+1;j<t;j++)
        {
            if(jojo[k].num < jojo[j].num)
            {
                temp = jojo[k];
                jojo[k] = jojo[j];
                jojo[j] = temp;
            }
        }
    }
}

int main(){

    int t;
    cin >> t;
    acm jojo[t];
    for(int i=0;i<t;i++)
    {
        jojo[i] = newAcm(i);
    }
    sort(t,jojo);
    printacm(t,jojo);
    return 0;
}