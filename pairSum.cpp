#include<iostream>
#include<vector>
using namespace std;
int main(){
   vector<int> arr = {2,7,11,15};
   vector<int> ans;
   int target = 18;
   int start=0; 
   int end= 3;
   while(start<end){
    int sum = arr[start]+arr[end];
    if(sum==target){
        ans.push_back(start);
        ans.push_back(end);
        break;
    }
    else if(sum>target){
        end--;
    }
    else{
        start++;
    }
   }
   cout<<" Indices";
   for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
   }
}