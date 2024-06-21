#include <iostream>
#include <cstring>
using namespace std;

int CompareStr(char* s1,char* s2);

int main(){

    int t;
    cin >> t;
    string str1,str2;
    
    while(t>0)
    {
        cin >> str1 >> str2;
        cout << CompareStr(&str1[0],&str2[0]) << endl;
        t--;
    }

    return 0;
}

int CompareStr(char* s1,char* s2)
{
    int leng1 = 0,leng2 = 0,i;
    for(i=1;;i++)
    {
        if(*(s1+i) == 0)
        {
            break;
        }
    }
    leng1 = i;
    for(i=1;;i++)
    {
        if(*(s2+i) == 0)
        {
            break;
        }
    }
    leng2 = i;

    if(leng1 == leng2)
    {
        int over2 = 0;
        for(i=0;i<leng1;i++)
        {
            if(*(s1+i) > *(s2+i))
            {
                over2++;
            }
        }
        if(over2 > (leng1 - over2))
        {
            return 1;
        }
        else if(over2 < (leng1 - over2))
        {
            return -1;
        }
        else 
        {
            return 0;
        }
    }
    else if(leng1 > leng2)
    {
        return 1;
    }
    else 
    {
        return -1;
    }
}