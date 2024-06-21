#include <iostream>
#include <string>
using namespace std;
int main(){

    static int Li,Zhang,Fu;
    char a1[3] = "Li",a2[6] = "Zhang",a3[3] = "Fu";
    int N;
    bool ava;
    char temp[6];
    int i,j;
    cin >> N;
    cin.get();
    for(i=0;i<N;i++)
    {
        ava = 1;
        cin.getline(temp,6);
        if(temp[0] == 'L')
        {
            for(j=1;j<6;j++)
            {
                if(a1[j] == 0)
                    break;
                else if(a1[j] != temp[j])
                {
                    ava = 0;
                }
            }
            if(ava == 1)
            {
                Li++;
            }
        }
        if(temp[0] == 'Z')
        {
            for(j=1;j<6;j++)
            {
                if(a2[j] == 0)
                    break;
                else if(a2[j] != temp[j])
                {
                    ava = 0;
                }
            }
            if(ava == 1)
            {
                Zhang++;
            }
        }
        if(temp[0] == 'F')
        {
            for(j=1;j<6;j++)
            {
                if(a3[j] == 0)
                    break;
                else if(a3[j] != temp[j])
                {
                    ava = 0;
                }
            }
            if(ava == 1)
            {
                Fu++;
            }
        }
    }
    cout << "Li:" << Li << endl;
    cout << "Zhang:" << Zhang << endl;
    cout << "Fu:" << Fu << endl;

    return 0;
}