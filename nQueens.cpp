#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<string> &board, int row, int col, int n){

    // Check same column
    for(int i=row-1; i>=0; i--){
        if(board[i][col]=='Q')
            return false;
    }

    // Left diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j]=='Q')
            return false;
    }

    // Right diagonal
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
        if(board[i][j]=='Q')
            return false;
    }

    return true;
}

void solve(vector<string> &board, int row, int n,
           vector<vector<string>> &result){

    if(row==n){
        result.push_back(board);
        return;
    }

    for(int col=0; col<n; col++){

        if(isValid(board,row,col,n)){

            board[row][col]='Q';

            solve(board,row+1,n,result);

            board[row][col]='.';
        }
    }
}

int main(){

    int n=4;

    vector<string> board(n,string(n,'.'));

    vector<vector<string>> result;

    solve(board,0,n,result);

    // Print all solutions
    for(int i=0;i<result.size();i++){

        cout<<"Solution "<<i+1<<endl;

        for(int j=0;j<n;j++){
            cout<<result[i][j]<<endl;
        }

        cout<<endl;
    }

    return 0;
}