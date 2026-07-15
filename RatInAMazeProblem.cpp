#include <iostream>
#include <vector>
using namespace std;

vector<string> result;

void solve(int row, int col, vector<vector<int>> &maze, int n, string path)
{
    // Boundary and blocked cell
    if(row < 0 || row >= n || col < 0 || col >= n || maze[row][col] == 0)
        return;

    // Destination reached
    if(row == n-1 && col == n-1)
    {
        result.push_back(path);
        return;
    }

    // Mark visited
    maze[row][col] = 0;

    // Left
    path.push_back('L');
    solve(row, col-1, maze, n, path);
    path.pop_back();

    // Right
    path.push_back('R');
    solve(row, col+1, maze, n, path);
    path.pop_back();

    // Up
    path.push_back('U');
    solve(row-1, col, maze, n, path);
    path.pop_back();

    // Down
    path.push_back('D');
    solve(row+1, col, maze, n, path);
    path.pop_back();

    // Backtrack
    maze[row][col] = 1;
}

int main()
{
    vector<vector<int>> maze =
    {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    int n = 4;

    solve(0, 0, maze, n, "");

    cout << "Possible Paths:\n";

    for(string s : result)
    {
        cout << s << endl;
    }

    return 0;
}