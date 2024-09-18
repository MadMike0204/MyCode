#include <iostream>
#include <stack>
using namespace std;

struct Pos
{
    int x;
    int y;
    int direction; // 方位 -1是起始位置的特殊值  (0:→ | 1:↓ | 2:← | 3:↑)
};

class Maze2D
{
    private:
        Pos destination;
        int size;
        int** maze;
        bool isAccessible;
        stack<Pos> path_reversed,path;
    public:
        Maze2D(int size)
        {
            this->size = size;
            maze = new int*[size];
            for(int i=0;i<size;i++)
            {
                maze[i] = new int[size];
            }
            isAccessible = 0;
            destination = {size-1,size-1,-1};
        }
        ~Maze2D()
        {
            if(maze != nullptr)
            {
                for(int i=0;i<size;i++)
                {
                    delete[] maze[i];
                }
                delete[] maze;
            }
        }
        int FindConsecutivePassage(Pos currentPos);
        Pos CurrentPostionAndNextDirectionToPosition(Pos currentPos,int Ndirection);
        void OnceWalk(int x,int y)
        {
            if(maze[x][y] != 1)
                maze[x][y] = -1;
        }
        void ResetWalk(int x,int y)
        {
            if(maze[x][y] != 1)
                maze[x][y] = 0;
        }
        void FindYourWayHome();//笑
        void InitialMaze()
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    cin >> maze[j][i];
                }
            }
        }
        void ReversePath()
        {
            Pos temp;
            while(!path_reversed.empty())
            {
                temp = path_reversed.top();
                path_reversed.pop();
                path.push(temp);
            }
        }
        void PrintPath()
        {
            Pos position;
            int i=0;
            if(path.empty())
            {
                cout << "no path" << endl;
                return;
            }
            while(!path.empty())
            {
                position = path.top();
                    cout << '[' << position.x << ',' << position.y << ']' << "--";
                if((++i)%4 == 0)
                    cout << endl;
                path.pop();
            }
            cout << "END" << endl;
        }
        void PrintMaze()
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    cout << maze[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
};
int Maze2D::FindConsecutivePassage(Pos currentPos)
{
    int originDirection = currentPos.direction;
    int possibleDirection = -1;
    if(originDirection == -1)
    {
        if(currentPos.x+1 < size && maze[currentPos.x+1][currentPos.y] == 0)
        {
            possibleDirection = 0;
        }
        else if(currentPos.y+1 < size && maze[currentPos.x][currentPos.y+1] == 0)
        {
            possibleDirection = 1;
        }
        else if(currentPos.x-1 >= 0 && maze[currentPos.x-1][currentPos.y] == 0)
        {
            possibleDirection = 2;
        }
        else if(currentPos.y-1 >= 0 && maze[currentPos.x][currentPos.y-1] == 0)
        {
            possibleDirection = 3;
        }
        return possibleDirection;
    }
    else
    {
        if(currentPos.x+1 < size && maze[currentPos.x+1][currentPos.y] == 0 && originDirection < 0)
        {
            possibleDirection = 0;
        }
        else if(currentPos.y+1 < size && maze[currentPos.x][currentPos.y+1] == 0 && originDirection < 1)
        {
            possibleDirection = 1;
        }
        else if(currentPos.x-1 >= 0 && maze[currentPos.x-1][currentPos.y] == 0 && originDirection < 2)
        {
            possibleDirection = 2;
        }
        else if(currentPos.y-1 >= 0 && maze[currentPos.x][currentPos.y-1] == 0 && originDirection < 3)
        {
            possibleDirection = 3;
        }
        return possibleDirection;
    }
}
Pos Maze2D::CurrentPostionAndNextDirectionToPosition(Pos currentPos,int Ndirection)
{
    Pos NPosition = currentPos;
    NPosition.direction = -1;
    switch(Ndirection)
    {
        case 0:
            NPosition.x++;
            break;
        case 1:
            NPosition.y++;
            break;
        case 2:
            NPosition.x--;
            break;
        case 3:
            NPosition.y--;
    }
    return NPosition;
}
void Maze2D::FindYourWayHome()
{
    path_reversed.push({0,0,-1});
    OnceWalk(0,0);
    Pos temp,next;
    int direction;
    while(!path_reversed.empty())
    {
        temp = path_reversed.top();
        if(temp.x == destination.x && temp.y == destination.y)
        {
            isAccessible = 1;
            break;
        }

        direction = FindConsecutivePassage(temp);
        if(direction != -1)
        {
            next = CurrentPostionAndNextDirectionToPosition(temp,direction);
            temp.direction = direction;
            path_reversed.push(next);
            OnceWalk(next.x,next.y);
        }
        else
        {
            path_reversed.pop();
        }
    }
}

void test()
{
    Maze2D jojo(4);
    jojo.InitialMaze();
    jojo.OnceWalk(1,2);
    jojo.PrintMaze();
}

int main(){

    test();
    // int t,n;
    // cin >> t;
    // while(t--)
    // {
    //     cin >> n;
    //     Maze2D jojo(n);
    //     jojo.InitialMaze();
    //     jojo.FindYourWayHome();
    //     jojo.ReversePath();
    //     jojo.PrintPath();
    // }

    return 0;
}