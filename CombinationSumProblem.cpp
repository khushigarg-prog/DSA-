#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s;

void getAllCombinations(vector<int>& arr, int idx, int target,
                        vector<vector<int>> &ans, vector<int> &comb)
{
    if(idx == arr.size() || target < 0)
        return;

    if(target == 0)
    {
        if(s.find(comb) == s.end())
        {
            ans.push_back(comb);
            s.insert(comb);
        }
        return;
    }

    comb.push_back(arr[idx]);

    // Include single time
    getAllCombinations(arr, idx + 1, target - arr[idx], ans, comb);

    // Include multiple times
    getAllCombinations(arr, idx, target - arr[idx], ans, comb);

    // Backtracking
    comb.pop_back();

    // Exclude current element
    getAllCombinations(arr, idx + 1, target, ans, comb);
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans;
    vector<int> comb;

    getAllCombinations(arr, 0, target, ans, comb);

    cout << "Combinations are:\n";

    for(auto v : ans)
    {
        cout << "[ ";
        for(int x : v)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}