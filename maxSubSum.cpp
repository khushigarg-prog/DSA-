#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int arr[] = {3,-4,5,4,-1,7,-8};
    int maxSum = INT_MIN;
    int currSum = 0;
    for(int val: arr){
        currSum=currSum+val;
        maxSum=max(maxSum,currSum);
        // By kadane's algorithm
        if(currSum<0){
            currSum=0;
        }
    }
    cout<<maxSum;
}