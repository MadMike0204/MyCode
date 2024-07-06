#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_LINES = 9;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;

void PrintTableHeader();
void PrintTableBody();

int main(){

    PrintTableHeader();
    PrintTableBody();

    return 0;
}

void PrintTableHeader()
{
    ifstream input("table-data.txt");
    for(int i=0;i<NUM_LINES;i++)
    {
        int intValue;
        double doubleValue;
        input >> intValue >> doubleValue;

        cout << setw(COLUMN_WIDTH) << (i+1) << " | "
             << setw(COLUMN_WIDTH) << intValue << " | "
             << fixed << setw(COLUMN_WIDTH) << doubleValue << " | " << endl;
    }
}
void PrintTableBody()
{
    for(int i=0;i<NUM_COLUMNS;i++)
    {
        for(int j=0;j<COLUMN_WIDTH;j++)
        {
            cout << "-";
        }
        cout << "-+-";
    }
    cout << endl;
}