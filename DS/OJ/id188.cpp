#include <iostream>
using namespace std;
#define MAX_SIZE 200

class ParentTree;
class ParentTreeNode
{
    friend class ParentTree;
    private:
        char data;
        int parent;
};
class ParentTree
{
    private:
        ParentTreeNode node[MAX_SIZE];
        int n; // 节点个数
        void PreorderTraverse(int curNode)
        {
            cout << node[curNode].data;
            for(int i=0;i<n;i++)
            {
                if(node[i].parent == curNode)
                {
                    PreorderTraverse(i);
                }
            }
        }
        
    public:
        ParentTree()
        {
            n = 0;
        }
        void PreorderTraverse()
        {
            int idx;
            for(int i=0;i<n;i++)
            {
                if(node[i].parent == -1)
                {
                    idx = i;
                    break;
                }
            }
            PreorderTraverse(idx);
        }
        void InitParentTree()
        {
            char ch; // 输入数据
            cin >> n; // 输入节点个数
            for(int i=0;i<n;i++)
            {
                cin >> node[i].data;
            }
            for(int i=0;i<n;i++)
            {
                cin >> node[i].parent;
            }
        }
        
};

int main(){

    int t;
    cin >> t;
    while(t--)
    {
        ParentTree JOJO;
        JOJO.InitParentTree();
        JOJO.PreorderTraverse();
        cout << endl;
    }

    return 0;
}