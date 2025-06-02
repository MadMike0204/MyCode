#include <iostream>
#include <vector>
#include <string>
class box {
private:
    std::string num; 
    int length;      
    int width;       
    int height;    

public:

    box(std::string n = "", int l = 0, int w = 0, int h = 0) : num(n), length(l), width(w), height(h) {}


    std::string getNum() const {
        return num;
    }


    int get_volume() const {
        return length * width * height;
    }


    int operator-(const box& inner_box) const {

        if (inner_box.length <= this->length &&
            inner_box.width <= this->width &&
            inner_box.height <= this->height) {

            return inner_box.get_volume();
        } else {

            return 0;
        }
    }
};

int main() {
    int n;

    std::cin >> n;

    std::vector<box> boxes_collection; 
    boxes_collection.reserve(n);     

    for (int i = 0; i < n; ++i) {
        std::string id_str;
        int l_val, w_val, h_val;

        std::cin >> id_str >> l_val >> w_val >> h_val;
        boxes_collection.emplace_back(id_str, l_val, w_val, h_val);
    }

    int max_total_overflow = -1; 
    std::string optimal_inner_box_id; 
    std::string optimal_outer_box_id; 


    if (n >= 2) {

        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue; 
                }


                int current_calculated_overflow = boxes_collection[i] - boxes_collection[j];

                if (current_calculated_overflow > max_total_overflow) {
                    max_total_overflow = current_calculated_overflow;
                    optimal_inner_box_id = boxes_collection[j].getNum(); 
                    optimal_outer_box_id = boxes_collection[i].getNum(); 
                }
            }
        }
    }
    if (max_total_overflow != -1) { 
        std::cout << optimal_inner_box_id << "盒子放入" << optimal_outer_box_id << "盒子溢出的水最多，为" << max_total_overflow << "。" << std::endl;
    } 
    return 0;
}