#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;
        
        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if (lmax < rmax) {
                ans = ans + lmax - height[l];
                l++;
            }
            else {
                ans = ans + rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example test case
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    int result = solution.trap(height);
    
    cout << "Total trapped rain water: " << result << " units" << endl;
    
    return 0;
}
