#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> st; 
        
        for (int i = 0; i < str.size(); i++) {
            // Push opening brackets to stack
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                st.push(str[i]); 
            } 
            else { 
                // Closing bracket with empty stack is invalid
                if (st.empty()) {
                    return false; 
                }
                
                char top_char = st.top(); // Added () fix
                if ((top_char == '(' && str[i] == ')') || 
                    (top_char == '[' && str[i] == ']') || 
                    (top_char == '{' && str[i] == '}')) {
                    st.pop(); 
                } else {
                    return false; 
                }
            }
        }
        return st.empty(); 
    }
};

// Driver code to test the function inside VS Code
int main() {
    Solution solver;
    
    // Test Case 1: Valid string
    string s1 = "()[]{}";
    cout << "Test 1 (" << s1 << "): " << (solver.isValid(s1) ? "true" : "false") << endl;

    // Test Case 2: Invalid string (Incorrect order)
    string s2 = "([)]";
    cout << "Test 2 (" << s2 << "): " << (solver.isValid(s2) ? "true" : "false") << endl;

    // Test Case 3: Invalid string (Unclosed bracket)
    string s3 = "(]";
    cout << "Test 3 (" << s3 << "): " << (solver.isValid(s3) ? "true" : "false") << endl;

    return 0;
}
