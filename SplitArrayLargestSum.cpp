#include<iostream>
using namespace std;
bool isValid(int arr[], int n, int k, int maxAllowedSum){
    int subarray=1, currSum=0;
    for(int i=0; i<n; i++){
        if(arr[i]>maxAllowedSum) return false;
        if(arr[i]+currSum<=maxAllowedSum){
            currSum+=arr[i];
        }
        else{
            subarray++;
            currSum=arr[i];
        }
    }
    if(subarray>k) return false;
    else return true;
}
int largestSum(int arr[], int n, int k){
    if(k>n) return -1;
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    int ans=-1;
    int start=0, end=sum; //Range of possible ans
    while(start<=end){
        int mid=start+(end-start)/2; //max allowed sum = mid
        if(isValid(arr,n,k,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {7,2,5,10,8};
    int n = 5, k=2; // k = no. of subarrays
    cout<<largestSum(arr,n,k);
}