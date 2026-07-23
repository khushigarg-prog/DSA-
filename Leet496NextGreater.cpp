#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution { 
public: 
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
        // Step1: We'll store nums2[i] and its next greater element in unordered_map 
        unordered_map<int,int> m; 
        stack<int> s; 
        
        for(int i=nums2.size()-1; i>=0; i--){ 
            while(s.size()>0 && s.top()<=nums2[i]){ 
                s.pop(); 
            } 
            if(s.empty()){ 
                m[nums2[i]]=-1; 
            } 
            else{ 
                m[nums2[i]]=s.top(); 
            } 
            s.push(nums2[i]); 
        } 
        
        // ab tkk humne sbh elements store krliye map k andr 
        // phir nums1 k elements ka next grater bs dhundenge map k andr 
        vector<int> ans; 
        for(int i=0; i<nums1.size(); i++){ 
            ans.push_back(m[nums1[i]]); 
        } 
        return ans; 
    } 
};

int main() {
    Solution solution;

    // Example input arrays
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    // Call the function
    vector<int> result = solution.nextGreaterElement(nums1, nums2);

    // Print the result
    cout << "Next Greater Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
