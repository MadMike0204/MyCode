#include <iostream>

using namespace std; // Use the std namespace

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printReverseHelper(Node* node, bool& isFirst) {
    if (node == nullptr) {
        return;
    }
    printReverseHelper(node->next, isFirst);

    if (isFirst) {
        cout << node->data;
        isFirst = false;
    } else {
        cout << " " << node->data;
    }
}

void reversePrint(Node* head) {
    if (head == nullptr) return;
    bool first = true;
    printReverseHelper(head, first);
}

void deleteList(Node* head) {
    Node* current = head;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Node* head = nullptr;
        Node* tail = nullptr;

        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        reversePrint(head);
        cout << " ";
        cout << endl;

        deleteList(head);
        head = nullptr;
        tail = nullptr;
    }
    return 0;
}
