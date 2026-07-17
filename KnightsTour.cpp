#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
    // Check boundaries and expected value
    if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal)
        return false;

    // Reached the last number
    if (expVal == n * n - 1)
        return true;

    // Try all 8 knight moves
    return isValid(grid, r - 2, c + 1, n, expVal + 1) ||
           isValid(grid, r - 1, c + 2, n, expVal + 1) ||
           isValid(grid, r + 1, c + 2, n, expVal + 1) ||
           isValid(grid, r + 2, c + 1, n, expVal + 1) ||
           isValid(grid, r + 2, c - 1, n, expVal + 1) ||
           isValid(grid, r + 1, c - 2, n, expVal + 1) ||
           isValid(grid, r - 1, c - 2, n, expVal + 1) ||
           isValid(grid, r - 2, c - 1, n, expVal + 1);
}

bool checkValidGrid(vector<vector<int>>& grid) {
    int n = grid.size();

    // Tour must start with 0
    if (grid[0][0] != 0)
        return false;

    return isValid(grid, 0, 0, n, 0);
}

int main() {
    int n;
    cout << "Enter the size of the grid: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Enter the grid:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if (checkValidGrid(grid))
        cout << "Valid Knight Tour\n";
    else
        cout << "Invalid Knight Tour\n";

    return 0;
}