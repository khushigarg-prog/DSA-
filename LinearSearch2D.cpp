#include <iostream>
#include <utility> // 1. Fixed: Changed <pairs> to <utility>
using namespace std;

int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int target = 7;
    bool found = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == target) {
                // 3. Fixed: Correct type declaration and initialization
                pair<int, int> ans = make_pair(i, j); 
                
                // 4. Fixed: Printed components individually
                cout << "Target found at index: (" << ans.first << ", " << ans.second << ")" << endl;
                found = true;
                break; // Exit inner loop since target is found
            }
            // 2. Fixed: Removed "else return -1" so the search can continue
        }
        if (found) break; // Exit outer loop
    }

    if (!found) {
        cout << "Target not found (-1)" << endl;
        return -1;
    }

    return 0;
}
