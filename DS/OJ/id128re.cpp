#include <iostream>
#include <stack>
using namespace std;

struct Pos {
    int x;
    int y;
    int direction; // 方位 -1是起始位置的特殊值  (0:→ | 1:↓ | 2:← | 3:↑)
};

class Maze2D {
private:
    Pos destination;
    int size;
    int** maze;
    bool isAccessible;
    stack<Pos> path_reversed, path;
public:
    Maze2D(int size) {
        this->size = size;
        maze = new int*[size];
        for (int i = 0; i < size; i++) {
            maze[i] = new int[size];
        }
        isAccessible = false;
        destination = { size - 1, size - 1, -1 };
    }

    ~Maze2D() {
        if (maze != nullptr) {
            for (int i = 0; i < size; i++) {
                delete[] maze[i];
            }
            delete[] maze;
        }
    }

    int FindConsecutivePassage(Pos currentPos);
    Pos CurrentPositionAndNextDirectionToPosition(Pos currentPos, int direction);
    void OnceWalk(int x, int y) {
        if (maze[x][y] != 1)
            maze[x][y] = -1; // 标记走过的路径
    }

    void ResetWalk(int x, int y) {
        if (maze[x][y] != 1)
            maze[x][y] = 0; // 还原路径标记
    }

    void FindYourWayHome(); // 查找路径
    void InitialMaze() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> maze[i][j];
            }
        }
    }

    void ReversePath() {
        while (!path_reversed.empty()) {
            path.push(path_reversed.top());
            path_reversed.pop();
        }
    }

    void PrintPath() {
        if (path.empty()) {
            cout << "no path" << endl;
            return;
        }

        Pos position;
        int i = 0;
        while (!path.empty()) {
            position = path.top();
            if ((++i) % 4 == 0)
                cout << '[' << position.x << ',' << position.y << ']' << "--" << endl;
            else
                cout << '[' << position.x << ',' << position.y << ']' << "--";
            path.pop();
        }
        cout << "END" << endl;
    }

    void PrintMaze() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int Maze2D::FindConsecutivePassage(Pos currentPos) {
    // 查找所有可能的通道，依次检查四个方向
    if (currentPos.x + 1 < size && maze[currentPos.x + 1][currentPos.y] == 0) // 向右
        return 0;
    if (currentPos.y + 1 < size && maze[currentPos.x][currentPos.y + 1] == 0) // 向下
        return 1;
    if (currentPos.x - 1 >= 0 && maze[currentPos.x - 1][currentPos.y] == 0)   // 向左
        return 2;
    if (currentPos.y - 1 >= 0 && maze[currentPos.x][currentPos.y - 1] == 0)   // 向上
        return 3;

    return -1; // 无通路
}

Pos Maze2D::CurrentPositionAndNextDirectionToPosition(Pos currentPos, int direction) {
    Pos nextPos = currentPos;
    nextPos.direction = -1;
    switch (direction) {
    case 0: nextPos.x++; break;  // 向右走
    case 1: nextPos.y++; break;  // 向下走
    case 2: nextPos.x--; break;  // 向左走
    case 3: nextPos.y--; break;  // 向上走
    }
    return nextPos;
}

void Maze2D::FindYourWayHome() {
    path_reversed.push({ 0, 0, -1 });
    OnceWalk(0, 0);  // 标记起点

    Pos current, next;
    int direction;
    while (!path_reversed.empty()) {
        current = path_reversed.top();

        if (current.x == destination.x && current.y == destination.y) {
            isAccessible = true;
            break;
        }

        direction = FindConsecutivePassage(current);
        if (direction != -1) {
            next = CurrentPositionAndNextDirectionToPosition(current, direction);
            path_reversed.push(next);
            OnceWalk(next.x, next.y);  // 标记新的路径点
        } else {
            path_reversed.pop(); // 退回上一步
        }
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        Maze2D maze(n);
        maze.InitialMaze();
        maze.FindYourWayHome();
        maze.ReversePath();
        maze.PrintPath();
    }
    return 0;
}
