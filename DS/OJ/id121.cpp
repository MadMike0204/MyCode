#include<iostream>
#include<queue>
using namespace std;
static const int MaxQ = 12;
static const int MaxSeq = 100;
static int info[MaxQ][MaxSeq];
static int seq[MaxSeq*MaxQ];
int GetWhichGroup(int id)
{
    for(int i=1;i<MaxQ;i++)
    {
        for(int j=0;j<MaxSeq;j++)
        {
            if(id == info[i][j])
            {
                return i;
            }
        }
    }
    return -1;
}

void Enqueue(queue<int> *spe,int id)
{
    int group = GetWhichGroup(id);
    spe[group].push(id);

    for(int i=0;i<MaxQ*MaxSeq;i++)
    {
        if(seq[i] == 0)
        {
            seq[i] = group;
            break;
        }
    }
}
void Dequeue(queue<int> &result,queue<int> *spe)
{
    int group;
    for(int i=0;i<MaxQ*MaxSeq;i++)
    {
        if(seq[i] != 0)
        {
            group = seq[i];
            seq[i] = 0;
            break;
        }
    }
    result.push(spe[group].front());
    spe[group].pop();
}
void FillInfo()
{
    int n,m;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> m;
        for(int j=0;j<m;j++)
        {
            cin >> info[i][j];
        }
    }
}

int main(){

    int id;
    queue<int> special[MaxQ];
    queue<int> result;

    FillInfo();

    string op;
    while(1)
    {
        cin >> op;
        if(op == "STOP")
            break;
        if(op == "ENQUEUE")
        {
            cin >> id;
            Enqueue(special,id);
            continue;
        }
        if(op == "DEQUEUE")
        {
            Dequeue(result,special);
        }
    }

    while(1)
    {
        id = result.front();
        result.pop();
        cout << id;
        if(result.empty())
        {
            break;
        }
        cout << " ";
    }

    return 0;
}