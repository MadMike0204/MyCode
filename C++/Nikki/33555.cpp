#include <iostream>
using namespace std;

int maze[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1}
};
int stepCount = 0;

int step[5][5] = {0};

bool visited[5][5] = {false};  // 用来标记是否访问过某个节点

// 定义四个方向：上、下、左、右
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// DFS 遍历
void dfs(int x, int y) {
    // 访问当前节点
    visited[x][y] = true;
    stepCount++;
    step[x][y] = stepCount;
    cout << "Visiting (" << x << ", " << y << ")\n";
    
    // 遍历四个方向
    for (int i = 0; i < 4; i++) {
        int new_x = x + directions[i][0];
        int new_y = y + directions[i][1];
        
        // 检查新位置是否在迷宫范围内，且该位置是 0 且未访问
        if (new_x >= 0 && new_x < 5 && new_y >= 0 && new_y < 5 && maze[new_x][new_y] == 0 && !visited[new_x][new_y]) {
            dfs(new_x, new_y);  // 递归访问
        }
    }
}

int main() {
    // 从第一个 0 节点开始遍历
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (maze[i][j] == 0 && !visited[i][j]) {
                dfs(i, j);
            }
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << step[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

