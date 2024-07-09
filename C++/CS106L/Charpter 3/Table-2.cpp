#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

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
    int rowNumber = 0;

    int intValue;
    double doubleValue;
    while(input >> intValue >> doubleValue)//简化终止流程
    {
        cout << setw(COLUMN_WIDTH) << (rowNumber+1) << " | "
             << setw(COLUMN_WIDTH) << intValue << " | "
             << fixed << setw(COLUMN_WIDTH) << doubleValue << " | " << endl;

        rowNumber++;
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