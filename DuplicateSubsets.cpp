#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void getAllSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets){
    if(i==nums.size()){
        allSubsets.push_back(ans);
        return;
    }
    // include
    ans.push_back(nums[i]);
    getAllSubsets(nums,ans,i+1,allSubsets);
    // backtrack
    ans.pop_back();
    // Exclude also avoid duplicates
    int idx=i+1;
    while(idx<nums.size() && nums[idx]==nums[idx-1]){
        idx++;
    }
    // Exclude
    getAllSubsets(nums,ans,idx,allSubsets); 
}
int main(){
    vector<int> nums = {1,2,2};
    // Step 1: Sort the given array
    sort(nums.begin(), nums.end());
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(nums,ans,0,allSubsets); // 0 is starting index
    // Print the final list of subsets
    for (int i = 0; i < allSubsets.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < allSubsets[i].size(); j++) {
            cout << allSubsets[i][j] << " ";
        }
        cout << "]\n";
    }
}