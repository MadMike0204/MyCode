#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int x, y;
    Node(int x = 0, int y = 0) : x(x), y(y) {}
};

int n, m, totalZeroArea, totalCells;
vector<vector<int>> matrix(200, vector<int>(200));
vector<vector<int>> visited(200, vector<int>(200));
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void bfs(int startX, int startY)
{
    queue<Node> q;
    q.push(Node(startX, startY));
    visited[startX][startY] = 1;
    totalZeroArea++;

    while (!q.empty())
    {
        Node current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                matrix[newX][newY] == 0 && !visited[newX][newY])
            {
                totalZeroArea++;
                visited[newX][newY] = 1;
                q.push(Node(newX, newY));
            }
        }
    }
}

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        totalZeroArea = totalCells = 0;
        fill(visited.begin(), visited.end(), vector<int>(200, 0));
        
        cin >> n >> m;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
                if (matrix[i][j] == 0)
                    totalCells++;
            }

        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0 && !visited[i][0])
                bfs(i, 0);
            if (matrix[i][m - 1] == 0 && !visited[i][m - 1])
                bfs(i, m - 1);
        }

        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] == 0 && !visited[0][i])
                bfs(0, i);
            if (matrix[n - 1][i] == 0 && !visited[n - 1][i])
                bfs(n - 1, i);
        }

        cout << totalCells - totalZeroArea << endl;
    }

    return 0;
}
