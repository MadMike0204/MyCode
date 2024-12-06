#include<iostream>
using namespace std;
class CNode
{
public:
    int data;
    CNode *left;
    CNode *right;
    CNode()
    {
        left=right=NULL;
    }
};
 
class BStree
{
public:
    CNode *root;
    BStree()
    {
        root=NULL;
    }
    void addTree(int number)
    {
        CNode *t=root;
        while(true)
        {
            if(number<t->data)
            {
                if(t->left==NULL)
                {
                    t->left=new CNode();
                    t->left->data=number;
                    return;
                }
                else
                {
                    t=t->left;
                }
            }
            else
            {
                if(t->right==NULL)
                {
                    t->right=new CNode();
                    t->right->data=number;
                    return;
                }
                else
                {
                    t=t->right;
                }
            }
        }
    }
    void printTree(CNode *p)
    {
        if(p)
        {
            printTree(p->left);
            cout<<p->data<<" ";
            printTree(p->right);
        }
    }
};
 
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        BStree Tree;
        for(int i=0;i<n;i++)
        {
            int c;
            cin>>c;
            if(i==0)
            {
                Tree.root=new CNode();
                Tree.root->data=c;
            }
            else
            {
                Tree.addTree(c);
            }
        }
        Tree.printTree(Tree.root);
        cout<<endl;
        int m;
        cin>>m;
        while(m--)
        {
            int ch;
            cin>>ch;
            Tree.addTree(ch);
            Tree.printTree(Tree.root);
            cout<<endl;
        }
    }
    return 0;
}