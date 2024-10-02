#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class CharPosition {
public:
    char character;
    int index;

    CharPosition() : character(' '), index(-1) {}

    CharPosition(char ch, int idx) : character(ch), index(idx) {}
};

class CharMatcher {
private:
    stack<CharPosition> charStack;
    string inputStr;
    char primaryChar, secondaryChar;

public:
    CharMatcher(const string& str) : inputStr(str), primaryChar(str[0]), secondaryChar(' ') {
        // 查找第二个不同的字符
        for (char c : str) {
            if (c != primaryChar) {
                secondaryChar = c;
                break;
            }
        }
    }

    void InitializePositions(vector<CharPosition>& positions) {
        for (int i = 0; i < (int)inputStr.size(); i++) {
            positions.emplace_back(inputStr[i], i);
        }
    }

    void MatchPairs() {
        vector<CharPosition> positions;
        InitializePositions(positions);
        
        charStack.push(positions[0]);
        
        for (int i = 1; i < (int)inputStr.size(); i++) {
            char currentChar = inputStr[i];

            if (currentChar == primaryChar) {
                charStack.push(positions[i]);
            } else if (currentChar == secondaryChar && !charStack.empty()) {
                CharPosition top = charStack.top();
                if (top.character == primaryChar) {
                    cout << top.index << " " << positions[i].index << endl;
                    charStack.pop();
                }
            }
        }
    }
};

int main() {
    string input;
    cin >> input;

    CharMatcher matcher(input);
    matcher.MatchPairs();

    return 0;
}
