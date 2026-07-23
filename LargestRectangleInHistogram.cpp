#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution { 
public: 
    int largestRectangleArea(vector<int>& heights) { 
        int n = heights.size(); 
        vector<int> left(n,0);  // Stores nearest smaller index on the left
        vector<int> right(n,0); // Stores nearest smaller index on the right
        stack<int> s; 

        // 1. Calculate right smaller nearest 
        for(int i=n-1; i>=0; i--){ 
            while(s.size()>0 && heights[s.top()]>=heights[i]){ 
                s.pop(); 
            } 
            if(s.empty()){ 
                right[i]=n; 
            } 
            else{ 
                right[i]=s.top(); 
            } 
            s.push(i); 
        } 

        // Clear the stack to reuse it
        while(!s.empty()){ 
            s.pop(); 
        } 

        // 2. Calculate left smaller nearest 
        for(int i=0; i<n; i++){ 
            while(s.size()>0 && heights[s.top()]>=heights[i]){ 
                s.pop(); 
            } 
            if(s.empty()){ 
                left[i]=-1; 
            } 
            else{ 
                left[i]=s.top(); 
            } 
            s.push(i); 
        } 

        // 3. Calculate the maximum area
        int ans=0; 
        for(int i=0; i<n; i++){ 
            int width=right[i]-left[i]-1; 
            int currArea = heights[i]*width; 
            ans = max(ans, currArea); 
        } 
        return ans; 
    } 
};

// Driver code to run and test in VS Code
int main() {
    Solution sol;
    
    // Test Case 1: Standard example
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Test 1 Max Area: " << sol.largestRectangleArea(heights1) << " (Expected: 10)" << endl;

    // Test Case 2: All elements same
    vector<int> heights2 = {2, 4};
    cout << "Test 2 Max Area: " << sol.largestRectangleArea(heights2) << " (Expected: 4)" << endl;

    return 0;
}
