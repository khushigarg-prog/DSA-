#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

unordered_set<int> cols;
unordered_set<int> diag;
unordered_set<int> antidiag;

void solve(vector<string> &board, int row, int n,
           vector<vector<string>> &result){

    // Base case
    if(row == n){
        result.push_back(board);
        return;
    }

    for(int col=0; col<n; col++){

        int diagConst = row + col;
        int antiDiagConst = row - col;

        // Check if queen can be placed
        if(cols.find(col) != cols.end() ||
           diag.find(diagConst) != diag.end() ||
           antidiag.find(antiDiagConst) != antidiag.end()){

            continue;
        }

        // Place queen
        cols.insert(col);
        diag.insert(diagConst);
        antidiag.insert(antiDiagConst);
        board[row][col] = 'Q';

        solve(board, row + 1, n, result);

        // Backtrack
        cols.erase(col);
        diag.erase(diagConst);
        antidiag.erase(antiDiagConst);
        board[row][col] = '.';
    }
}

int main(){

    int n = 4;

    vector<string> board(n, string(n,'.'));

    vector<vector<string>> result;

    solve(board, 0, n, result);

    // Print all solutions
    for(int i=0; i<result.size(); i++){

        cout << "Solution " << i+1 << endl;

        for(int j=0; j<n; j++){
            cout << result[i][j] << endl;
        }

        cout << endl;
    }

    return 0;
}