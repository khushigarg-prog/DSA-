#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> result;
        for(int i = 0; i < n; i++) {
            // Step 1: Remove elements outside the current window
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            } 
            // Step 2: Remove smaller elements in the current window
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            } 
            // Step 3: Push current index
            dq.push_back(i); 
            // Step 4: Add the maximum of the current window to results
            if(i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> ans = sol.maxSlidingWindow(nums, k);
    
    cout << "Sliding window maximums: ";
    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
