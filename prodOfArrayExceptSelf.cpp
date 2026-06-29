#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]); 
    vector<int> ans(n, 1);
    ans[0] = 1;
    for(int i=1; i<n; i++){
        ans[i]=ans[i-1]*nums[i-1];
    }
    int suffix=1;
    for(int i=n-2; i>=0; i--){
       suffix=nums[i+1]*suffix;
       ans[i]=ans[i]*suffix;
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}
