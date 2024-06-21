#include <iostream>
using namespace std;

class Bulk{
    private:
        int length;
        int width;
        int height;
        int volume;
    public:
        void setBulk()
        {
            cin >> length >> width >> height;
        }
        int get_volume()
        {
            return (length*width*height);
        }
        int get_areas()
        {
            int area = 2 * (length*width + length*height + width*height);
            return area;
        }
        void print_volume()
        {
            cout << get_volume() << endl;
        }
        void print_areas()
        {
            cout << get_areas() << endl;
        }
};

int main(){

    Bulk newnew;
    newnew.setBulk();
    newnew.print_volume();
    newnew.print_areas();

    return 0;
}