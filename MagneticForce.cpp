#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
bool isValid(vector<int> &arr, int n, int m, int minAllowedDistance){
    int balls=1, lastPos=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]-lastPos >= minAllowedDistance){
            balls++;
            lastPos=arr[i];
        }
        if(balls==m) return true;
    }
    return false;
}
int getDistance(vector<int> &arr, int n, int m){
    if(m>n) return -1;
    sort(arr.begin(), arr.end());
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for(int i=0; i<n; i++){
        smallest=min(smallest,arr[i]);
        largest=max(largest,arr[i]);
    }
    int start=1; // min distance between 2 balls
    int end = largest-smallest; // max distance between 2 balls
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(arr,n,m,mid)){
            ans=mid;
            start=mid+1; //to find largest possible ans
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr= {1,2,3,4,7};
    int n = 5; // no. of baskets
    int m = 3 ; // no. of balls
    cout<<getDistance(arr,n,m);
}