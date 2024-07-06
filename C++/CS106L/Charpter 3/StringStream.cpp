#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
int main(){

    stringstream JOJO;
    JOJO << "JOJO 190 17";
    int height,year;
    string name;
    JOJO >> name >> height >> year;
    cout << name << " " << height << " " << year;

    return 0;
}