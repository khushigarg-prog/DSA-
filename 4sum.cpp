#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> ans;
    int n = 6;
    // i is for 1st no....j for 2nd..p for 3rd & q for 4th
    int target = 0;
    //Step 1 is to sort the array
    sort(nums.begin(), nums.end());
    //Step 2 is to select the num 1 by i and num 2 by j 
    // after that select 3rd & 4th number accoridng to target
    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int p=j+1;
            int q = n-1;
            while(p<q){
            long long sum = (long long)nums[i]+nums[j]+nums[p]+nums[q];
            if(sum>target){
                q--;
            }
            else if(sum<target){
                p++;
            }
            else{
                // got the ans
                ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                while(p<q && nums[p]==nums[p+1]) p++;
                while(p<q && nums[q]==nums[q-1]) q--;
                p++;
                q--; 
            }
        }
        }
    }
    // Print the ans
    for(auto t: ans){
        cout<<t[0]<<" "<<t[1]<<" "<<t[2]<<" "<<t[3]<<"\n";
    }
}