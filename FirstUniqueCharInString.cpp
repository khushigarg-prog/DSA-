#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Solution { 
public: 
    int firstUniqChar(string s) { 
        unordered_map<char,int> mp; 
        queue<int> q; 
        
        for(int i=0; i<s.size(); i++){ 
            // if char does not exist in map
            if(mp.find(s[i]) == mp.end()){ 
                q.push(i); // pushes index rather than char 
            } 
            mp[s[i]]++; 
            
            // Pop elements from queue if they are no longer unique
            while(q.size() > 0 && mp[s[q.front()]] > 1){ 
                q.pop(); 
            } 
        } 
        
        if(q.empty()) return -1; 
        else{ 
            return q.front(); 
        } 
    } 
};

int main() {
    Solution solver;
    
    // Test cases
    string test1 = "leetcode";
    string test2 = "loveleetcode";
    string test3 = "aabb";
    
    cout << "Index in '" << test1 << "': " << solver.firstUniqChar(test1) << " (Expected: 0)" << endl;
    cout << "Index in '" << test2 << "': " << solver.firstUniqChar(test2) << " (Expected: 2)" << endl;
    cout << "Index in '" << test3 << "': " << solver.firstUniqChar(test3) << " (Expected: -1)" << endl;
    
    return 0;
}
