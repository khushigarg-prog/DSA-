#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
    vector<vector<int>> grid = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6}
    };
    
    vector<int> ans;
    unordered_set<int> s;
    int n = 3;
    int a = 0; // repeating value
    int b = 0; // missing value
    int expSum = 0, actualSum = 0; 
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            actualSum += grid[i][j]; // FIX 1: Accumulate sum using +=
            
            // If a number already exists in set, it is the duplicate
            if(s.find(grid[i][j]) != s.end()){
                a = grid[i][j];
            }
            s.insert(grid[i][j]);
        }
    }
    
    // Calculate expected sum for numbers 1 to n^2
    expSum = (n * n) * (n * n + 1) / 2;
    
    // Calculate missing value
    b = expSum + a - actualSum;
    
    // Store both values in the answer vector
    ans.push_back(a);
    ans.push_back(b);
    
    // FIX 2: Correct way to print the elements
    cout << "Repeating: " << ans[0] << ", Missing: " << ans[1] << endl;
    
    return 0;
}
