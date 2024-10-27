#include <iostream>
using namespace std;
#define MAX_SIZE 60

class ChildTree;
class ChildTreeNode;

class ChildTreeNode
{
    friend class ChildTree;
    private:
        int child;
        ChildTreeNode* next;
    public:
        ChildTreeNode(){}
};
class ChildTreeBox
{
    friend class ChildTree;
    private:
        char data;
        ChildTreeNode* firstchild;
};
class ChildTree
{
    private:
        ChildTreeBox nodes[MAX_SIZE];
        int n,root;// n 节点数量，树根位置
        void PostOrderTraverse(int curNode)
        {   
            ChildTreeNode* ptr = nodes[curNode].firstchild;
            while(ptr->child != -1 && ptr->next != nullptr)
            {
                PostOrderTraverse(ptr->child);
                ptr = ptr->next;
            }

            cout << nodes[curNode].data;
        }
    public:
        ChildTree()
        {
            n = 0;
            root = 0;
        }
        void PostOrderTraverse()
        {
            PostOrderTraverse(root);
        }
        void InitialTree()
        {
            int child;
            cin >> n;
            cin >> root;
            for(int i=0;i<n;i++)
            {
                cin >> nodes[i].data;
                nodes[i].firstchild = new ChildTreeNode;
                nodes[i].firstchild->next = nullptr;

                ChildTreeNode* ptr = nodes[i].firstchild;
                while(cin >> child)
                {
                    if(child == -1)
                    {
                        ptr->child = -1;
                        ptr->next = nullptr;
                        break;
                    }
                    ptr->child = child;
                    ptr->next = new ChildTreeNode;
                    ptr = ptr->next;
                }
            }
        }
};

int main(){

    ChildTree tree;
    tree.InitialTree();
    tree.PostOrderTraverse();

    return 0;
}
