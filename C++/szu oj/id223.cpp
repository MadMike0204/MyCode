#include <iostream>
#include <string>
using namespace std;

class Document
{
    protected:
        string name;
    public:
        Document(const string &name_in):
            name(name_in)
        {

            cout << "Create Document Class" << endl;
        }
        void Print()
        {
            cout << "Document Name is " << name << endl;
        }
        ~Document()
        {
            cout << "Delete Document Class" << endl;
        }
};
class Book:public Document
{
    protected:
        int pageCount;
    public:
        Book(const string &name_in,int pageCount_in):
            Document(name_in),pageCount(pageCount_in)
        {
            cout << "Create Book Class" << endl;
        }
        void Print()
        {
            cout << "Document Name is " << name << endl
                 << "PageCount is " << pageCount << endl;
        }
        ~Book()
        {
            cout << "Delete Book Class" << endl;
        }
};

int main(){

    int pagecount;
    string name;
    cin >> name >> pagecount;
    Book joker(name,pagecount);
    joker.Print();

    return 0;
}