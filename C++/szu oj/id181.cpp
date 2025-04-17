#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    string name;
    string position;
    int rating;
    
    // 静态成员变量记录各位置球员数量
    static int pgCount;
    static int sgCount;
    static int sfCount;
    static int pfCount;
    static int cCount;
    
public:
    // 构造函数
    Player(const string& name, const string& position, int rating) {
        this->name = name;
        this->position = position;
        this->rating = rating;
        
        // 增加相应位置计数
        if (position == "PG") pgCount++;
        else if (position == "SG") sgCount++;
        else if (position == "SF") sfCount++;
        else if (position == "PF") pfCount++;
        else if (position == "C") cCount++;
    }
    
    // 显示球员信息
    void displayInfo() const {
        cout << "Name:" << name << " Position:" << position << " Rate:" << rating << endl;
    }
    
    // 静态方法显示各位置球员统计
    static void displayStats() {
        cout << "Total PG Player:" << pgCount << endl;
        cout << "Total SG Player:" << sgCount << endl;
        cout << "Total SF Player:" << sfCount << endl;
        cout << "Total PF Player:" << pfCount << endl;
        cout << "Total C Player:" << cCount << endl;
    }
};

// 初始化静态成员变量
int Player::pgCount = 0;
int Player::sgCount = 0;
int Player::sfCount = 0;
int Player::pfCount = 0;
int Player::cCount = 0;

int main() {
    string name, position;
    int rating;
    
    // 存储球员对象
    Player* players[100]; // 假设不超过100名球员
    int count = 0;
    
    while (true) {
        cin >> name;
        if (name == "0") break;
        
        cin >> position >> rating;
        players[count++] = new Player(name, position, rating);
    }
    
    // 显示所有球员信息
    for (int i = 0; i < count; i++) {
        players[i]->displayInfo();
    }
    cout << endl;
    
    // 显示位置统计
    Player::displayStats();
    
    // 释放内存
    for (int i = 0; i < count; i++) {
        delete players[i];
    }
    
    return 0;
}
