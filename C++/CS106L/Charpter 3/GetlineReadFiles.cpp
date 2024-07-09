#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
int main(){
    //创建in-stream,如果读取失败则打印失败消息并终止程序
    ifstream capitals("world-capitals.txt");
    if(!capitals.is_open())
    {
        cerr << "Cannot find the file world-capitals.txt" << endl;
        return -1;
    }
    // while(1)
    // {
    //     string capital,country;
    //     getline(capitals,capital);
    //     getline(capitals,country);
    //     if(capitals.fail()) break;
    // }
    string capital,country;
    while(getline(capitals,capital) && getline(capitals,country))
    {
        cout << capital << "is the capital of " << country << endl;
    }

    return 0;
}