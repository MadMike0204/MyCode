#include <iostream>
using namespace std;
class BitNode {
    char data;
    int tag;
    BitNode* lChild, *rChild;
    BitNode() {
        lChild = nullptr;
        rChild = nullptr;
        tag = 0;
    }
    BitNode(int ch) :data(ch), lChild(nullptr),rChild(nullptr){};
    friend class BitTree;
};
class BitTree {
    BitNode* root;
    int len;
    
public:
    BitTree() {
        root = nullptr;
        len = 0;
        
    }
    void CreateTree() {
        root = CreateBitTree();
    }
    BitNode *CreateBitTree() {
        BitNode* T;
        char ch;
        cin >> ch;;
        if (ch == '#')
            T = nullptr;
        else {
            T = new BitNode(ch);
            T->lChild = CreateBitTree();
            T->rChild = CreateBitTree();
        }
       return T;
        
        
    }
    void Traverse() {
        Traverse(root);
    }
    void Traverse(BitNode* t) {
        if (t) {
            Traverse(t->lChild);
            Traverse(t->rChild);
            BitNode* tmp = new BitNode();
            tmp = t->rChild;
            t->rChild = t->lChild;
            t->lChild = tmp;
        }
        else {
            return;
        }
        
    }
    void FirstOrder() {
        if (root==nullptr)
            cout << "NULL";
        else
            FirstOrder(root);
        cout << endl;
    }
   void FirstOrder(BitNode *t) {
       
        if (!t) {
            return;
        }
        else {
            cout << t->data << " ";
            FirstOrder(t->lChild);
            FirstOrder(t->rChild);
        }
    }
    
   void LastOrder() {
       if (root == nullptr)
           cout << "NULL";
       else
           LastOrder(root);
       cout << endl;
       
   }
   void LastOrder(BitNode* t) {
       if (!t) {
           return;
       }
       else {

           LastOrder(t->lChild);
           LastOrder(t->rChild);
           cout << t->data <<" ";
       }
   }
   void MidOrder() {
       if (root == nullptr)
           cout << "NULL";
       else
           MidOrder(root);
       cout << endl; 
   }
   void MidOrder(BitNode* t) {
       if (!t) {
           return;
       }
       else {

           MidOrder(t->lChild); 
           cout << t->data << " ";
           MidOrder(t->rChild);
          
       }
   }
   void level_Order() {
       if (root == nullptr)
           cout << "NULL";
       else
           level_Order(root);
       cout << endl;

   }
   void level_Order(BitNode* t)
   {
       BitNode *a[1000];
       int pos = 0,front=0;
       BitNode* p = t;
       a[pos++]= p;
           while (1)
           {
               p = a[front];
               front++;
               cout << p->data << ' ';
               if (p->lChild)
                   a[pos++] = (p->lChild);
               if (p->rChild)
                   a[pos++] = (p->rChild);
               if (front==pos)
                   break;
           }
   }
};
int main()
{   
    int t;
    cin >> t;
    while (t--) {
        string str;
        BitTree Tree;
        
        Tree.CreateTree();
        Tree.Traverse();
        Tree.FirstOrder();
        Tree.MidOrder();
        Tree.LastOrder();
        Tree.level_Order();
    }
}
