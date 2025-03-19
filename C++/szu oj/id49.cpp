#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

enum class Suit {
    方块, 梅花, 红桃, 黑桃, 王
};

// 权重映射 名字-大小
static map<string,int> weightMap = {
    {"3", 1}, {"4", 2}, {"5", 3}, {"6", 4}, 
    {"7", 5}, {"8", 6}, {"9", 7}, {"10", 8},
    {"J", 9}, {"Q", 10}, {"K", 11}, {"A", 12}, 
    {"2", 13},{"小王", 14}, {"大王", 15}
};

struct Card {
    Suit suit;   // 花色
    string rank; // 牌的名字
    int weight;  // 大小

    Card(Suit s, string r) : suit(s), rank(r), weight(weightMap[r]) {}

    // 重载 < ,方便排序
    bool operator < (const Card &other) const {
        return this->weight < other.weight;
    }
};

// 打印牌堆
void printCard(vector<Card> &cards){
    for(int i = 0;i<cards.size();i++){
        Card& c = cards[i];
        if(c.suit == Suit::王)
            cout << c.rank << " ";
        else {
            string suitStr;
            switch (c.suit) {
                case Suit::方块: suitStr = "方块"; break;
                case Suit::梅花: suitStr = "梅花"; break;
                case Suit::红桃: suitStr = "红桃"; break;
                case Suit::黑桃: suitStr = "黑桃"; break;
                default: suitStr = ""; break;
            }
            cout << suitStr << c.rank;
        }
        if(i != cards.size()-1){
            cout << " ";
        }
    }
    cout << endl;
}

// 解析花色
Suit parseSuit(const string &s) {
    if (s == "方块") return Suit::方块;
    if (s == "梅花") return Suit::梅花;
    if (s == "红桃") return Suit::红桃;
    if (s == "黑桃") return Suit::黑桃;
    return Suit::王;
}

int main(){

    int t;
    cin >> t;
    vector<Card>cards;
    string line; // 整行扑克牌
    while(t--){
        int n;
        cin >> n;
        cin.ignore(); // 清缓冲

        getline(cin,line);
        stringstream ss(line);// 重输入开始处理

        string card;
        while (ss >> card) {
            if (card == "小王" || card == "大王") {
                cards.emplace_back(Suit::王, card);
            } else {
                string rank = card.substr(2); // 提取点数
                string suitStr = card.substr(0, 2); // 提取花色
                cards.emplace_back(parseSuit(suitStr), rank); // push
            }
        }
        // 输入完 并且重载 < 可以sort
        sort(cards.begin(),cards.end());
        printCard(cards);
        cards.clear();
    }
    return 0;
}