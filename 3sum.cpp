#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    
    // Sort to handle duplicates and use two pointers
    sort(arr.begin(), arr.end()); 
    vector<vector<int>> result;

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate values for the first element
        if (i > 0 && arr[i] == arr[i - 1]) continue; 

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum > 0) {
                right--;
            } 
            else if (sum < 0) {
                left++;
            } 
            else {
                result.push_back({arr[i], arr[left], arr[right]});

                // Skip duplicate values for second and third elements
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;

                left++;
                right--;
            }
        }
    }

    // Simplified print loop
    for (auto t : result) {
        cout << t[0] << " " << t[1] << " " << t[2] << "\n";
    }

    return 0;
}
