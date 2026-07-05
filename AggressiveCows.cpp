#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
bool isValid(vector<int> &arr, int n, int c, int minAllowedDistance){
    int cows=1, lastStallPos=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]-lastStallPos>=minAllowedDistance){
            cows++;
            lastStallPos=arr[i];
        }
        if(cows==c){
            return true;
        }
    }
    return false;
}
int getDistance(vector<int> &arr, int n, int c){
    sort(arr.begin(), arr.end());
    if(c>n) return -1;
    // To find max possible min distance
    int smallest = INT_MAX;
    int largest = INT_MIN; 
    for(int i=0; i<n; i++){
        smallest=min(smallest,arr[i]);
        largest=max(largest,arr[i]);
    }
    int start = 1; // min dist b/w 2 cows is 1
    int end=largest-smallest; // largest val of array - smallest val of array
    int ans = -1;
    while(start<=end){
        int mid=start+(end-start)/2; // min allowed distance
        if(isValid(arr,n,c,mid)){
            ans=mid;
            start=mid+1; // to find the max possible ans 
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int n=5; // no. of stalls
    int c=3; // no. of cows
    vector<int> arr = {1,2,8,4,9};
    cout<<getDistance(arr,n,c);
}