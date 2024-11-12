#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct Node
{
    int x, y;
    Node() : x(0), y(0) {}
};

int n, m, tot0, sum;
int mp[200][200], mark[200][200];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void bfs(int x, int y)
{
    queue<Node> q;
    Node st, ed;
    st.x = x, st.y = y;
    q.push(st);
    mark[st.x][st.y] = 1;
    tot0++;
    while (q.size())
    {
        st = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ed.x = st.x + dx[i], ed.y = st.y + dy[i];
            if (ed.x >= 0 && ed.x < n && ed.y >= 0 && ed.y < m && !mp[ed.x][ed.y] && !mark[ed.x][ed.y])
            {
                tot0++;
                mark[ed.x][ed.y] = 1;
                q.push(ed);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        tot0 = sum = 0;
        memset(mark, 0, sizeof(mark));
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
                if (mp[i][j] == 0)
                    sum++;
            }
        for (int i = 0; i < n; i++)
        {
            if (!mp[i][0] && !mark[i][0])
                bfs(i, 0);
            if (!mp[i][m - 1] && !mark[i][m - 1])
                bfs(i, m - 1);
        }
        for (int i = 0; i < m; i++)
        {
            if (!mp[0][i] && !mark[0][i])
                bfs(0, i);
            if (!mp[n - 1][i] && !mark[n - 1][i])
                bfs(n - 1, i);
        }
        cout << sum - tot0 << endl;
    }
    return 0;
}