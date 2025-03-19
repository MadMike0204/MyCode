#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

enum class Suit {
    Diamonds, Clubs, Hearts, Spades, Joker
};

static map<string, int> weightMap = {
    {"3", 1}, {"4", 2}, {"5", 3}, {"6", 4}, 
    {"7", 5}, {"8", 6}, {"9", 7}, {"10", 8},
    {"J", 9}, {"Q", 10}, {"K", 11}, {"A", 12}, 
    {"2", 13}, {"小王", 14}, {"大王", 15}
};


static map<string, Suit> suitMap = {
    {"方块", Suit::Diamonds}, {"梅花", Suit::Clubs}, 
    {"红桃", Suit::Hearts}, {"黑桃", Suit::Spades}
};

struct Card {
    Suit suit;  
    string rank;
    int weight; 

    Card(Suit s, string r) : suit(s), rank(r), weight(weightMap[r]) {}


    bool operator < (const Card &other) const {
        return this->weight < other.weight;
    }
};

// Print sorted cards
void printCards(const vector<Card> &cards) {
    for (size_t i = 0; i < cards.size(); i++) {
        if (cards[i].suit == Suit::Joker) {
            cout << cards[i].rank;
        } else {
            string suitStr;
            for (const auto &pair : suitMap) {
                if (pair.second == cards[i].suit) {
                    suitStr = pair.first;
                    break;
                }
            }
            cout << suitStr << cards[i].rank;
        }
        if (i != cards.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    vector<Card> cards;
    string line;

    while (t--) {
        int n;
        cin >> n;
        cin.ignore(); 

        getline(cin, line);
        stringstream ss(line);
        string cardStr;

        while (ss >> cardStr) {
            if (cardStr == "小王" || cardStr == "大王") {
                cards.emplace_back(Suit::Joker, cardStr);
            } else {
                string suitStr = cardStr.substr(0, 2); 
                string rank = cardStr.substr(2);     
                cards.emplace_back(suitMap[suitStr], rank);
            }
        }

        sort(cards.begin(), cards.end());

        printCards(cards);

        cards.clear();
    }
    
    return 0;
}
