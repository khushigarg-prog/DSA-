#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Your LeetCode Solution Class
class Solution { 
public: 
    vector<int> nextGreaterElements(vector<int>& nums) { 
        int n = nums.size(); 
        vector<int> ans(n, -1); 
        stack<int> s; 
        
        for(int i = 2 * n - 1; i >= 0; i--) { 
            while(s.size() > 0 && nums[s.top()] <= nums[i % n]) { 
                s.pop(); 
            } 
            if(s.empty()) { 
                ans[i % n] = -1; 
            } else { 
                ans[i % n] = nums[s.top()]; 
            } 
            s.push(i % n); 
        } 
        return ans; 
    } 
};

// Driver Code for VS Code
int main() {
    Solution solver;
    
    // Example test case: [1, 2, 1]
    vector<int> testInput = {1, 2, 1};
    
    // Call the function
    vector<int> result = solver.nextGreaterElements(testInput);
    
    // Print the results
    cout << "Output: [";
    for(size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
