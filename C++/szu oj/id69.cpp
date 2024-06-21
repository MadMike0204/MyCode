#include <iostream>
#include <cstring>
using namespace std;



int main(){

    int t,n;
    static char result[33];
    char* to_result = &result[0];
    cin >> t;
    while(t > 0)
    {
        to_result = &result[0];
        char str1[11],str2[11],str3[11];
        cin >> str1 >> str2 >> str3;
        char* p1 = str1;
        char* p2 = str2;
        char* p3 = str3;
        int a,b;
        int borden;
        cin >> a >> b;
        borden = b-a;
        int i;
        for(i=a-1;i<b;i++)
        {
            *(to_result) = *(p1+i);
            to_result++;
        }
        cin >> a >> b;
        for(i=a-1;i<b;i++)
        {
            *(to_result) = *(p2+i);
            to_result++;
        }
        cin >> a >> b;
        for(i=a-1;i<b;i++)
        {
            *(to_result) = *(p3+i);
            to_result++;
        }
        cout << result << endl;
        t--;
        memset(result,0,sizeof(result));
    }


    return 0;
}