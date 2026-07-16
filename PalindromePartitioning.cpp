#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans) {
        // Base Case
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        // Try every possible prefix
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);

            // If prefix is palindrome
            if (isPalindrome(part)) {
                partitions.push_back(part);

                // Recursive call on remaining string
                getAllParts(s.substr(i + 1), partitions, ans);

                // Backtracking
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);
        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter the string: ";
    cin >> s;

    vector<vector<string>> ans = obj.partition(s);

    cout << "\nAll Palindrome Partitions:\n";

    for (auto partition : ans) {
        cout << "[ ";
        for (auto str : partition) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}