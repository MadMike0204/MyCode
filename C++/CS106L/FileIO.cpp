#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){

    ifstream Mystring;
    string FileName;
    FileName = "MyFile.txt";
    Mystring.open(FileName.c_str());

    if(!Mystring.is_open())
        cerr << "Could not open Myfile" << endl;
    
    ofstream MyWriter("WriterTester.txt");
    

    return 0;
}