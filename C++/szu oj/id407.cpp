#include<iostream>
using namespace std;
int main(){
    int grade;
    char g;
    cin >> grade;
    switch(grade){
        case 90 ... 100:
            g = 'A';
            break;
        case 80 ... 89:
            g = 'B';
            break;
        case 70 ... 79:
            g = 'C';
            break;
        case 60 ... 69:
            g = 'D';
            break;
        case 0 ... 59:
            g = 'F';
            break;
        default:
            g = 'e';
    }
    if(g == 'e')
        cout << "error" << endl;
    else    
        cout << g << endl;



    return 0;
}