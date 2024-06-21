#include <iostream>
#include <string>
using namespace std;
int main(){

    int t;
    char Str[30];
    cin >> t;
    cin.get();
    while(t>0)
    {
        cin.getline(Str,30);
        int i,location;
        for(i=0;i<29;i++)
        {
            if(Str[i] == 0)
                break;
            else if(Str[i] >='A' && Str[i] <= 'Z')
            {
                location = Str[i] - 65;
                location += 4;
                location %= 26;
                Str[i] = 65 + location;
            }
            else if(Str[i] >='a' && Str[i] <= 'z')
            {
                location = Str[i] - 97;
                location += 4;
                location %= 26;
                Str[i] = 97 + location;
            }
        }
        cout << Str << endl;
        t--;
    }

    return 0;
}